# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.8)


set (CMAKE_BUILD_TYPE Debug)

FIND_LIBRARY(ZMQ_LIB zmq)
FIND_LIBRARY(UV_LIB libuv)
MESSAGE(STATUS "linking to zmq " ${ZMQ_LIB})
MESSAGE(STATUS "linking to libuv " ${UV_LIB})

add_executable(srv srv.cpp)
target_link_libraries (srv ${ZMQ_LIB}) 

add_executable(cl test.cpp)
target_link_libraries (cl ${ZMQ_LIB})


