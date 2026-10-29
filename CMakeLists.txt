cmake_minimum_required(VERSION 3.10)
project(StudentuPrograma CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(programa 
    main.cpp 
    funkcijos.cpp 
    funkcijos.h 
    studentas.h
)
