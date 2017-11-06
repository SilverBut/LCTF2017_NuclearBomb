cmake_minimum_required(VERSION 3.0)
project(performance_compare)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out/)
find_package(CUDA QUIET REQUIRED)

# Pass options to NVCC
set(
    CUDA_NVCC_FLAGS
    ${CUDA_NVCC_FLAGS};
    -arch=sm_53
)
 
# Specify binary name and source file to build it from
cuda_add_executable(
    matrix_gpu
	    src/matrix_gpu.cu
)

add_executable(
	matrix_cpu
		src/matrix_cpu.c
)

add_custom_command(
	TARGET matrix_gpu
	POST_BUILD
	COMMAND /usr/bin/time ${CMAKE_CURRENT_BINARY_DIR}/matrix_gpu
)

add_custom_command(
	TARGET matrix_cpu
	POST_BUILD
	COMMAND /usr/bin/time ${CMAKE_CURRENT_BINARY_DIR}/matrix_cpu
)
