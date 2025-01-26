// tests/GitHubCLITests.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <presentation/cli/GitHubCLI.hpp>
#include <mocks/MockGitHubService.hpp>

using ::testing::Return;
using ::testing::_;

// Test fixture for GitHubCLI
class GitHubCLITest : public ::testing::Test {
protected:
    MockGitHubService mockService;
    GitHubCLI cli{mockService};
};

// Test listing repositories
TEST_F(GitHubCLITest, ListRepositories) {
    // Arrange
    std::vector<Repository> repos = {
        {"repo1", "https://github.com/user/repo1"},
        {"repo2", "https://github.com/user/repo2"}
    };
    EXPECT_CALL(mockService, listRepositories())
        .WillOnce(Return(repos));

    // Act (simulate user input)
    std::istringstream input("1\n");
    std::cin.rdbuf(input.rdbuf());

    // Capture output
    testing::internal::CaptureStdout();
    cli.run();
    std::string output = testing::internal::GetCapturedStdout();

    // Assert
    EXPECT_TRUE(output.find("Name: repo1, URL: https://github.com/user/repo1") != std::string::npos);
    EXPECT_TRUE(output.find("Name: repo2, URL: https://github.com/user/repo2") != std::string::npos);
}

// Test invalid option
TEST_F(GitHubCLITest, InvalidOption) {
    // Arrange (no expectations on mockService)

    // Act (simulate user input)
    std::istringstream input("999\n");
    std::cin.rdbuf(input.rdbuf());

    // Capture output
    testing::internal::CaptureStdout();
    cli.run();
    std::string output = testing::internal::GetCapturedStdout();

    // Assert
    EXPECT_TRUE(output.find("Invalid option!") != std::string::npos);
}