cmake_minimum_required(VERSION 3.30)
project(cryptopals)

set(CMAKE_CXX_STANDARD 20)

add_executable(cryptopals
        main.cpp
        cryptoutils.cpp
        challenge01.cpp
        challenge02.cpp
        challenge03.cpp
        challenge04.cpp
        challenge05.cpp)
