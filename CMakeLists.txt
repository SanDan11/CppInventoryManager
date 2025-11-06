cmake_minimum_required(VERSION 3.10)
project(CppInventoryManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(CppInventoryManager
    src/main.cpp
    src/inventory_manager.cpp
    src/database_manager.cpp
)

target_include_directories(CppInventoryManager PUBLIC include)

set(SQLite3_INCLUDE_DIR "C:/sqlite3")
set(SQLite3_LIBRARY "C:/sqlite3/sqlite3.lib")

target_include_directories(CppInventoryManager PUBLIC ${SQLite3_INCLUDE_DIR})
target_link_libraries(CppInventoryManager ${SQLite3_LIBRARY})
