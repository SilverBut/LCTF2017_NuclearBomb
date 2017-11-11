#include "nuclear_core.hpp"

#define ror32(p,q) ( ( (p) >> (q) ) | ( (p) << ( 32 - (q) ) ) )
#define assert_cuda() do {	\
	assert(!cudaGetLastError());\
	cudaDeviceSynchronize();	\
} while(0);

typedef unsigned long uint32_t;
#include "flag.hpp"
#include <cassert>

__global__ void _do_bomb(const unsigned char* gpu_sbox, unsigned char* stream){
  int blockId = blockIdx.x + blockIdx.y * gridDim.x  
                   + gridDim.x * gridDim.y * blockIdx.z;  
  int threadId = blockId * (blockDim.x * blockDim.y * blockDim.z)  
                     + (threadIdx.z * (blockDim.x * blockDim.y))  
                     + (threadIdx.y * blockDim.x) + threadIdx.x;  	
	unsigned int *stream_int = (unsigned int*)stream;
	// For each int, ROR a value
	unsigned char ror_value = threadIdx.x ^ threadIdx.y;
	if ( threadId % 4 == 0 ){
		stream_int[threadId/4]=ror32(stream_int[threadId/4], ror_value);
	}
	stream[threadId] = gpu_sbox[stream[threadId]];
}

int do_bomb(unsigned int* stream){

	unsigned char* dev_stream;
	unsigned char* dev_sbox;

	cudaMalloc((void**)&dev_stream, table_size * table_nlen * 4);
	cudaMemcpy(dev_stream, stream, table_size*table_nlen*4, cudaMemcpyHostToDevice);
	assert_cuda();

	cudaMalloc((void**)&dev_sbox, 256);
	cudaMemcpy(dev_sbox, sbox, 256, cudaMemcpyHostToDevice);
	assert_cuda();

	_do_bomb<<< dim3(4,table_nlen,1), dim3(table_block_width, table_block_width, 1) >>>(dev_sbox, dev_stream);
	assert_cuda();

	cudaMemcpy(stream, dev_stream, table_size*table_nlen*4, cudaMemcpyDeviceToHost);
	assert_cuda();

	cudaFree(dev_stream);
	cudaFree(dev_sbox);
	assert_cuda();

	return 0;
}
