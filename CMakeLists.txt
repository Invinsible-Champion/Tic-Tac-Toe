cmake_minimum_required(VERSION 3.10)
project(tictactoe_server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(server
    main.cpp
    generate_moves.cpp
    board.cpp
)

target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

target_link_libraries(server
    Threads::Threads
    Boost::system
)
