project(GitHubAPILib_Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(TEST_SOURCES

#)

#set(SOURCES

#)

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

add_executable(GitHubAPILib_Tests ${TEST_SOURCES} ${SOURCES})

target_link_libraries(GitHubAPILib_Tests PRIVATE
   gtest
	gtest_main
	gmock
)

enable_testing()

add_test(NAME GitHubAPILib_Tests COMMAND GitHubAPILib_Tests)
