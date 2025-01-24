# Nom du projet de test
project(GitHubAPILib_Tests LANGUAGES CXX)

# Options de compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ajouter les fichiers de test
set(TEST_SOURCES
    unit/presentation/GitHubCLITests.cpp
)

# Ajouter les fichiers sources nécessaires pour les tests
set(SOURCES
    ../src/presentation/GitHubCLI.cpp
)

# Ajouter les répertoires d'inclusion
include_directories(
   ../include
	.
)

# Télécharger et configurer Google Test et Google Mock
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include
	${gmock_SOURCE_DIR}/include
   ${CMAKE_SOURCE_DIR}/external)
# Créer l'exécutable de test
add_executable(GitHubAPILib_Tests ${TEST_SOURCES} ${SOURCES})

# Lier les bibliothèques nécessaires
target_link_libraries(GitHubAPILib_Tests PRIVATE
   gtest
	gtest_main
	gmock
   github  # Lier la bibliothèque principale
)

# Activer CTest pour gérer les tests
enable_testing()

# Ajouter les tests à CTest
add_test(NAME GitHubAPILib_Tests COMMAND GitHubAPILib_Tests)
