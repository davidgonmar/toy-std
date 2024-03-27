cmake_minimum_required(VERSION 3.14)

project(toy-std)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

enable_testing()

add_subdirectory(tests)


