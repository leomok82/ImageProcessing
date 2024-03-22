cmake_minimum_required(VERSION 3.10)  # Minimum version of CMake required

project(Yen_Project_Version_1)  # Name of your project

set(CMAKE_CXX_STANDARD 17)  # Specify the C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the -O3 optimization flag for all build types
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

file(GLOB SOURCES "src/*.cpp")  # Add all source files under the src directory

add_executable(Yen_Project ${SOURCES})  # Define an executable target
