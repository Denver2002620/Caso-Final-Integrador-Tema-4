cmake_minimum_required(VERSION 3.16)
project(TinyLispInterpreter)

# Set the C++ standard to C++11 or higher (C++17 is recommended)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and include the json11 library
# Make sure to adjust the path according to where you have json11 installed
set(JSON11_DIR "/path/to/json11")  # Update this to the actual path

# Adding the json11 library
include_directories(${JSON11_DIR})

# Add executable and specify the source files
add_executable(TinyLispInterpreter main.cpp Variant.cpp)

# If json11 is built as a library, link it with your executable
# If you compiled json11 as a static or shared library, specify its target name
# Here, you can directly compile from the json11 source if needed
# For example, if json11 is a header-only library, this may not be necessary:
# target_link_libraries(TinyLispInterpreter json11)

# Optionally, print the paths for debugging
message(STATUS "JSON11 Directory: ${JSON11_DIR}")