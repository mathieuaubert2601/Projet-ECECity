cmake_minimum_required(VERSION 3.23)
project(Projet_ECECity C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(.)

INCLUDE_DIRECTORIES(C:/Program Files/JetBrains/CLion 2022.2.4/bin/mingw/x86_64-w64-mingw32/include)
LINK_DIRECTORIES(C:/Program Files/JetBrains/CLion 2022.2.4/bin/mingw/x86_64-w64-mingw32/lib)

add_executable(Projet_ECECity
        header.h
        main.c
        init_allegro.c
        MenuJeu.c
        gestionBouton.c map.c
        sauvegarde.c)


target_link_libraries(Projet_ECECity -lmingw32 -lalleg44)

