cmake_minimum_required(VERSION 3.0)
project(nuclear_bomb)
find_package(CUDA QUIET REQUIRED)
set (CMAKE_CXX_STANDARD 11)

# Pass options to NVCC
set(
    CUDA_NVCC_FLAGS
    ${CUDA_NVCC_FLAGS};
    -arch=sm_53
)
 
# Set a output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./out/)

#add_definitions(-DSOLVE_FLAG)

# Specify binary name and source file to build it from
cuda_add_executable(
	nuclear_bomb
		src/nuclear_bomb.cpp
		src/nuclear_core.cpp
		src/nuclear_core.cu
)

#add_custom_command(
#	TARGET matrix_gpu
#	POST_BUILD
#	COMMAND /usr/bin/time ${CMAKE_CURRENT_BINARY_DIR}/matrix_gpu
#)
#
#add_custom_command(
#	TARGET matrix_cpu
#	POST_BUILD
#	COMMAND /usr/bin/time ${CMAKE_CURRENT_BINARY_DIR}/matrix_cpu
#)
