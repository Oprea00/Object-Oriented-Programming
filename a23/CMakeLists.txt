cmake_minimum_required(VERSION 3.17)
project(a23_Oprea00 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(a23_Oprea00
        domain/Country.c
        domain/Country.h repository/Repository.h repository/Repository.c controller/Controller.c controller/Controller.h ui/UI.c ui/UI.h main.c repository/DynamicArray.c repository/DynamicArray.h tests/tests.c tests/tests.h)
