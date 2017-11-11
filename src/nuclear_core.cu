#include "nuclear_core.hpp"

__global__ void _cu_do_add(const int* inputA, const int* inputB, int* output) {
	*output = *inputA + *inputB;
}


int do_add(int inputA, int inputB){

	int  output;
	int *dev_inputA, *dev_inputB, *dev_Output;
	
	cudaMalloc((void**)&dev_inputA, sizeof(int));
	cudaMalloc((void**)&dev_inputB, sizeof(int));
	cudaMalloc((void**)&dev_Output, sizeof(int));

	cudaMemcpy(dev_inputA, &inputA, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_inputB, &inputB, sizeof(int), cudaMemcpyHostToDevice);

	_cu_do_add<<<1, 1>>>(dev_inputA, dev_inputB, dev_Output);

	cudaMemcpy(&output, dev_Output, sizeof(int), cudaMemcpyDeviceToHost);

	cudaFree(dev_inputA);
	cudaFree(dev_inputB);
	cudaFree(dev_Output);

	return output;
}
