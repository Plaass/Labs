cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(test_complex Polinom.c Info-numbers.c Types/Complex.c Types/Int.c Types/Real.c Tests/test_complex.c test.c)
add_executable(test_float Polinom.c Info-numbers.c Types/Complex.c Types/Int.c Types/Real.c Tests/test_float.c)
add_executable(test_int Polinom.c Info-numbers.c Types/Complex.c Types/Int.c Types/Real.c Tests/test_int.c )
