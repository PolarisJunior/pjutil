cmake_minimum_required(VERSION 3.15)

project(
    pjutil
    VERSION 0.0.0
    LANGUAGES CXX
)

set(LIB_NAME ${PROJECT_NAME})
set(BIN_NAME ${PROJECT_NAME}bin)
# Name of the output binary executable.
# We have this separate so we can have the executable and library have the same name
set(BIN_OUTPUT_NAME ${PROJECT_NAME})

set(ALL_TARGETS ${LIB_NAME} ${BIN_NAME})

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(SRC_DIR src)

find_package(GTest QUIET)
option(TEST_ENABLED "" ${GTEST_FOUND})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_compile_options(-Wall -Wextra)

add_library(
    ${LIB_NAME}
    INTERFACE
)

target_include_directories(
    ${LIB_NAME}
    INTERFACE
    include
)

target_link_libraries(
    ${LIB_NAME}
    INTERFACE
    Threads::Threads
    project_options
    project_warnings
)

add_executable(
    ${BIN_NAME}
    ${SRC_DIR}/main.cpp
)

target_link_libraries(
    ${BIN_NAME}
    PRIVATE
    ${LIB_NAME}
    project_options
    project_warnings
)

set_target_properties(
    ${BIN_NAME}
    PROPERTIES
    OUTPUT_NAME ${BIN_OUTPUT_NAME}
)

if (${TEST_ENABLED})
    enable_testing()
    add_subdirectory(test)
endif()
