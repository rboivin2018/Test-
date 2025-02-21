project(GitHubAPILib_Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TEST_SOURCES
	unit/application/services/GitHubServiceTests.cpp
	unit/application/clients/GitHubAPIClientTests.cpp
)

set(SOURCES
	../src/application/services/GithubService.cpp
	../src/infrastructure/gateways/RepositoryGateway.cpp
	../src/application/clients/GitHubAPIClient.cpp
	../src/infrastructure/clients/CurlHttpClient.cpp
)

include_directories(
   ../include
	.
)

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

find_package(CURL REQUIRED)

add_executable(GitHubAPILib_Tests ${TEST_SOURCES} ${SOURCES})

target_include_directories(GitHubAPILib_Tests PRIVATE
    ${CURL_INCLUDE_DIRS}
)

target_link_libraries(GitHubAPILib_Tests PRIVATE
   gtest
	gtest_main
	gmock
	${CURL_LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(GitHubAPILib_Tests
  EXTRA_ARGS --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/test_results/
)

enable_testing()

add_test(NAME GitHubAPILib_Tests COMMAND GitHubAPILib_Tests)
