# Version minimale de CMake requise
cmake_minimum_required(VERSION 3.14)

# Nom du projet de test
project(GitHubAPILib_Tests LANGUAGES CXX)

# Options de compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ajouter les fichiers de test
set(TEST_SOURCES unit/*/*.cpp)

        # Ajouter les fichiers sources du projet (nécessaires pour les tests)
        set(SOURCES
                ../src/GitHubAPIClient.cpp
                    ../src/GitHubService.cpp
                    )

                # Ajouter les fichiers d'en-tête du projet
                set(HEADERS
                        ../include/GitHubAPIClient.hpp
                            ../include/GitHubService.hpp
                            )

                        # Créer un exécutable pour les tests
                        add_executable(GitHubAPILib_Tests ${TEST_SOURCES} ${SOURCES} ${HEADERS})

                        # Ajouter Catch2 (si vous utilisez Catch2)
                        include(FetchContent)
                        FetchContent_Declare(
                                Catch2
                                    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                                        GIT_TAG        v3.3.2

                            )
                        FetchContent_MakeAvailable(Catch2)

                        # Lier Catch2 et les dépendances aux tests
                        target_link_libraries(GitHubAPILib_Tests PRIVATE Catch2::Catch2WithMain)

                        # Ajouter les dépendances (par exemple, libcurl)
                        find_package(CURL REQUIRED)
                        target_link_libraries(GitHubAPILib_Tests PRIVATE CURL::CURL)

                        # Activer CTest pour gérer les tests
                        enable_testing()

                        # Ajouter les tests à CTest
                        add_test(NAME GitHubAPILib_Tests COMMAND GitHubAPILib_Tests)
