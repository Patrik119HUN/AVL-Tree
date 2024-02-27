cmake_minimum_required(VERSION 3.22)
project(avl_node)

set(CMAKE_CXX_STANDARD 17)

add_executable(avl_node
        src/node.cpp
        helpers.h
        include/rotations.h
        include/height.h
        include/balance.h
        src/height.cpp
        include/other.h
        include/Node.h
)
