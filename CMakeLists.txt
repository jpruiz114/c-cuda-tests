cmake_minimum_required(VERSION 3.30)
project(cuda_tests C)

set(CMAKE_C_STANDARD 11)

add_executable(cuda_tests cuda/cuda-test-1.c)
