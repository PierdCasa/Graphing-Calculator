cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyExecutable)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/function.cpp
    ${PROJECT_SOURCE_DIR}/rpn.cpp
    ${PROJECT_SOURCE_DIR}/token.cpp
    ${PROJECT_SOURCE_DIR}/evaluate.cpp
    ${PROJECT_SOURCE_DIR}/interface.cpp

)

# Include directories for headers
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
)

# Create the executable
add_executable(main ${SOURCES})
