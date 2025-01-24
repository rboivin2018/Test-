cmake_minimum_required(VERSION 3.14)

# Nom du projet
project(github LANGUAGES CXX)

# Options de compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ajouter les fichiers sources du projet
set(SOURCES
    src/GitHubAPIClient.cpp
)

# Add include directories
include_directories(
    include
)

# Créer une bibliothèque statique ou partagée
add_library(github STATIC ${SOURCES})

# Ajouter les dépendances (par exemple, libcurl)
find_package(CURL REQUIRED)
target_link_libraries(github PRIVATE CURL::CURL)

# Inclure le dossier des en-têtes
target_include_directories(github PUBLIC include)

# Tests
enable_testing()
add_subdirectory(tests)

# Optionally, for debugging or additional configuration
# set(CMAKE_VERBOSE_MAKEFILE ON)
# add_definitions(-DDEBUG)