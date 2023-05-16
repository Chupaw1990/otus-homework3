cmake_minimum_required(VERSION 3.12.0)
project(numbers VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(numbers  main.cpp
                        random_value.cpp
                        guess.cpp
                        file_managment.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
