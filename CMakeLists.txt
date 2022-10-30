cmake_minimum_required(VERSION 3.23)
project(Projet_ECECity C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_ECECity
        header.h
        main.c init_allegro.c)

target_link_libraries(Projet_ECECity -lmingw32 -lalleg44)


