cmake_minimum_required(VERSION 3.14)

project(github LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${nlohmann_json_SOURCE_DIR})

set(SOURCES
    src/main.cpp
    src/application/services/GithubService.cpp
    src/domain/use_cases/ListRepository.cpp
    src/infrastructure/clients/GithubAPIClient.cpp
    src/infrastructure/gateways/RepositoryGateway.cpp
    src/presentation/GitHubCLI.cpp
)
# Télécharger nlohmann/json.hpp
file(DOWNLOAD
        https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp
            ${CMAKE_SOURCE_DIR}/external/nlohmann/json.hpp
            )

        # Ajouter le chemin d'inclusion pour nlohmann/json
      include_directories(${CMAKE_SOURCE_DIR}/external)
include_directories(include)

find_package(CURL REQUIRED)

add_library(github STATIC ${SOURCES})

target_link_libraries(github PRIVATE CURL::libcurl)

target_include_directories(github PUBLIC include)

enable_testing()
add_subdirectory(tests)

# Optionally for debugging or additional configuration
# set(CMAKE_VERBOSE_MAKEFILE ON)
# add_definitions(-DDEBUG)
