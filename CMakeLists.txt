cmake_minimum_required(VERSION 3.23)
project(listas_enlazadas)

set(CMAKE_CXX_STANDARD 14)

add_executable(listas_enlazadas main.cpp NodoDE.cpp NodoDE.h List.cpp List.h ListDE.cpp ListDE.h ListSE.cpp ListSE.h NodoSE.cpp NodoSE.h)
