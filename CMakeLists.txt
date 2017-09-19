cmake_minimum_required(VERSION 3.8)
project(mkl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
        /opt/home/intel/mkl/include
)

link_directories(
        /opt/home/intel/lib/intel64_lin
        /opt/home/intel/mkl/lib/intel64_lin
)

set(SOURCE_FILES main.cpp)
add_executable(mkl ${SOURCE_FILES})

target_link_libraries(
        mkl
        mkl_intel_lp64.a
        mkl_intel_thread.a
        mkl_core.a
        iomp5
        pthread
        dl
        m
)

