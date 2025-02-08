cmake_minimum_required(VERSION 3.10)

#Nom du projet
project(GameExecutable)

include(CTest)
enable_testing()
set(CMAKE_C_FLAGS "-std=c99 -Wall --coverage -g")

#création des librairies
add_library(cards_lib cards.c)

#ajout des exécutables
add_executable(eight-american eight-american.c)
add_executable(cards_test cards_test.c)

#ajout des librairies aux exécutables
target_link_libraries(eight-american cards_lib)
target_link_libraries(cards_test cards_lib)


