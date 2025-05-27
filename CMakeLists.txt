cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)
set (SOURCES 
    ${PROJECT_SOURCE_DIR}/main.cpp 
    ${PROJECT_SOURCE_DIR}/app.cpp
    ${PROJECT_SOURCE_DIR}/fonts.cpp  
    ${PROJECT_SOURCE_DIR}/texts.cpp 
    ${PROJECT_SOURCE_DIR}/OXOY.cpp 
    ${PROJECT_SOURCE_DIR}/drawable.cpp
    ${PROJECT_SOURCE_DIR}/zoom.cpp
    ${PROJECT_SOURCE_DIR}/evaluate.cpp
    ${PROJECT_SOURCE_DIR}/function.cpp
    ${PROJECT_SOURCE_DIR}/rpn.cpp
    ${PROJECT_SOURCE_DIR}/token.cpp
    ${PROJECT_SOURCE_DIR}/typecheck.cpp
     ${PROJECT_SOURCE_DIR}/legenda.cpp








    )
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}
)
#egal cu nr de .cpp

# Create the executable

#add_executable(main /home/mario/Desktop/whaat/trig.cpp)
add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
