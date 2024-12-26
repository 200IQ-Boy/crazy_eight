cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(GameExecutable)

# Spécifie le standard C utilisé
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Ajout des fichiers sources
set(SOURCES
    game.c
    cards.c
)

# Création de l'exécutable
add_executable(game_executable ${SOURCES})

# Ajout des options pour afficher les warnings
target_compile_options(game_executable PRIVATE -Wall -Wextra -Wpedantic)

# Lien avec les bibliothèques standard si nécessaire (math ou autres)
target_link_libraries(game_executable m)
