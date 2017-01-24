cmake_minimum_required(VERSION 3.3)
project(xiao_algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#        common/sqlist-1.c
#        common/sqlist-2.c
        common/linklist.c)

add_executable(xiao_algorithm ${SOURCE_FILES})