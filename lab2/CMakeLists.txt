cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp)

add_executable(TestsSecuence.cpp Tests/TestsSecuence.cpp)

add_executable(TestsVector.cpp Tests/TestsVector.cpp)
