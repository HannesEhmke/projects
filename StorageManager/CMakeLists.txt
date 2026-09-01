cmake_minimum_required(VERSION 3.20)
project(StorageManager VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build test suite" ON)

# Core Library
add_library(storage_core
    src/Item.cpp
    src/Inventory.cpp
    src/OrderProcessor.cpp
)

target_include_directories(storage_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# App
add_executable(storage_manager src/main.cpp)
target_link_libraries(storage_manager PRIVATE storage_core)

# Tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()