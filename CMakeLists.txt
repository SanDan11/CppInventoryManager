cmake_minimum_required(VERSION 3.10)
project(CppInventoryManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppInventoryManager
    src/main.cpp
    src/item.cpp
    src/inventory_Manager.cpp
)

target_include_directories(CppInventoryManager PUBLIC include)
# find_package(SQLite3 REQUIRED)
# target_link_libraries(CppInventoryManager SQLite::SQLite3)
