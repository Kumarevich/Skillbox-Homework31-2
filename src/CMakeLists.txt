cmake_minimum_required(VERSION 3.22)

add_executable(Homework_31_2 main.cpp IGraph.cpp ListGraph.cpp MatrixGraph.cpp ${MY_INCLUDE_DIR}/IGraph.h ${MY_INCLUDE_DIR}/ListGraph.h ${MY_INCLUDE_DIR}/MatrixGraph.h)
target_include_directories(Homework_31_2 PUBLIC ${MY_INCLUDE_DIR})