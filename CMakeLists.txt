cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(chessrepbuilder VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(include include/object include/utils)

# Find all .cpp files in src/ and its subdirectories
file(GLOB_RECURSE SRCS "src/*.cpp")

# Specify the output directory for object files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# Add the executable
add_executable(${PROJECT_NAME} ${SRCS})

# Set the output directories for the target
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)
