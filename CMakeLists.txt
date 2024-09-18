cmake_minimum_required(VERSION 3.26)
project(LabMephi2)

set(CMAKE_CXX_STANDARD 23)

add_executable(LabMephi2 main.cpp
        test.h
        realization.h
        interface.h
        vector.h)
