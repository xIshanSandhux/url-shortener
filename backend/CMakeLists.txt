cmake_minimum_required(VERSION 3.16)
project(url_shortener_backend)

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Build Type (default = Release)
# -----------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# -----------------------------
# Find Dependencies
# -----------------------------
find_package(Boost REQUIRED COMPONENTS system)
find_package(SQLite3 REQUIRED)

# -----------------------------
# Source Files
# -----------------------------
add_executable(url_shortener
    src/main.cpp
    src/server.cpp
    src/router.cpp
    src/database.cpp
)

# -----------------------------
# Include Directories
# -----------------------------
target_include_directories(url_shortener PRIVATE
    src
)

# -----------------------------
# Link Libraries
# -----------------------------
target_link_libraries(url_shortener
    Boost::system
    SQLite::SQLite3
)

# -----------------------------
# Compiler Warnings
# -----------------------------
target_compile_options(url_shortener PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# ----------------------------
# Optimization Flags
# -----------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(url_shortener PRIVATE -O3)
endif()
