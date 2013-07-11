# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.8)

FIND_LIBRARY(ZMQ_LIB zmq)

add_executable(srv srv.cpp)
target_link_libraries (srv ${ZMQ_LIB}) 

add_executable(cl test.cpp)
target_link_libraries (cl ${ZMQ_LIB})


