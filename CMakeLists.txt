cmake_minimum_required(VERSION 3.22)
project(avl_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(avl_tree main.cpp
        avl_tree.h
        container_interface.h
        node.h
        iterator.h
        node.cpp
)
