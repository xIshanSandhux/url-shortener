cmake_minimum_required(VERSION 3.16)
project(url_shortener_backend)

# setting cpp to cpp v11 for now
set(CMAKE_CXX_STANDARD 17)

# to ensure boost is installed
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)


add_executable(backend
    src/connection.cpp
    src/shorten.cpp
    src/server.cpp
    src/main.cpp
)
target_include_directories(backend PRIVATE
    src/
)

target_link_libraries(backend PRIVATE
    Boost::boost
    Threads::Threads
)
