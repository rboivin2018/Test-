#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include <stdexcept>

#include <infrastructure/gateways/RepositoryGateway.hpp>
#include <mocks/MockRepositoryGateway.hpp>
#include <application/services/GitHubService.hpp>

using namespace testing;


TEST(GitHubServiceTest, ListRepositories_WhenGatewayReturnsNonEmptyList_ReturnsSameList) {
    MockRepositoryGateway gateway;
    std::vector<Repository> expectedRepos = {
        Repository(std::string("repo1"), std::string("https://github.com/user/repo1")),
        Repository(std::string("repo2"), std::string("https://github.com/user/repo2"))
    };

    // Configuration du mock
    EXPECT_CALL(gateway, listRepositories())
        .Times(1)
        .WillOnce(Return(expectedRepos));

    GitHubService service(gateway);
    auto actualRepos = service.listRepositories();

    // Vérification de la taille et des données
    ASSERT_EQ(actualRepos.size(), expectedRepos.size());
    
    for (size_t i = 0; i < actualRepos.size(); i++) {
        EXPECT_EQ(actualRepos[i].name, expectedRepos[i].name);
        EXPECT_EQ(actualRepos[i].url, expectedRepos[i].url);
    }
}

TEST(GitHubServiceTest, ListRepositories_WhenGatewayReturnsEmptyList_ReturnsEmptyList) {
    MockRepositoryGateway gateway;
    
    EXPECT_CALL(gateway, listRepositories())
        .Times(1)
        .WillOnce(Return(std::vector<Repository>{}));

    GitHubService service(gateway);
    auto result = service.listRepositories();

    ASSERT_TRUE(result.empty());
}

TEST(GitHubServiceTest, ListRepositories_WhenGatewayThrowsException_PropagatesException) {
    MockRepositoryGateway gateway;

    EXPECT_CALL(gateway, listRepositories())
        .Times(1)
        .WillOnce(Throw(std::runtime_error("API Error")));

    GitHubService service(gateway);

    ASSERT_THROW({
        service.listRepositories();
    }, std::runtime_error);
}

TEST(GitHubServiceTest, ListRepositories_VerifyGatewayInteraction) {
    MockRepositoryGateway gateway;

    EXPECT_CALL(gateway, listRepositories())
        .Times(1)
        .WillOnce(Return(std::vector<Repository>{}));

    GitHubService service(gateway);
    service.listRepositories();
}

// Matcher personnalisé pour comparer les Repository
MATCHER_P(RepositoryEqual, expected, "") {
    return arg.name == expected.name && 
           arg.url == expected.url &&
           arg.description == expected.description &&
           arg.isPrivate == expected.isPrivate;
}

TEST(GitHubServiceTest, ListRepositories_WithCustomMatcher_ComparesRepositories) {
    MockRepositoryGateway gateway;
    Repository expectedRepo("test_repo", "http://github.com/test/repo");
    
    EXPECT_CALL(gateway, listRepositories())
        .WillOnce(Return(std::vector{expectedRepo}));

    GitHubService service(gateway);
    auto result = service.listRepositories();

    ASSERT_THAT(result, Contains(RepositoryEqual(expectedRepo)));
}

TEST(GitHubServiceTest, ListRepositories_WithLargeDataset_HandlesCorrectly) {
    MockRepositoryGateway gateway;
    
    // Génération de 1500 repositories
    std::vector<Repository> massiveList;
    for(int i = 0; i < 1500; i++) {
        massiveList.emplace_back(
            "repo_" + std::to_string(i),
            "https://github.com/user/repo_" + std::to_string(i)
        );
    }

    EXPECT_CALL(gateway, listRepositories())
        .WillOnce(Return(massiveList));

    GitHubService service(gateway);
    auto result = service.listRepositories();

    ASSERT_EQ(result.size(), 1500);
    EXPECT_THAT(result, Contains(RepositoryEqual(massiveList.front())));
    EXPECT_THAT(result, Contains(RepositoryEqual(massiveList.back())));
}

TEST(GitHubServiceTest, ListRepositories_WithDifferentExceptions_PropagatesCorrectly) {
    MockRepositoryGateway gateway;

    // Test avec std::bad_alloc
    EXPECT_CALL(gateway, listRepositories())
        .WillOnce(Throw(std::bad_alloc()));
    
    GitHubService service1(gateway);
    EXPECT_THROW(service1.listRepositories(), std::bad_alloc);

    // Test avec std::invalid_argument
    EXPECT_CALL(gateway, listRepositories())
        .WillOnce(Throw(std::invalid_argument("Invalid param")));
    
    GitHubService service2(gateway);
    EXPECT_THROW(service2.listRepositories(), std::invalid_argument);
}

TEST(GitHubServiceTest, ListRepositories_MultipleCalls_VerifiesInteractionCount) {
    MockRepositoryGateway gateway;

    EXPECT_CALL(gateway, listRepositories())
        .Times(Exactly(3))
        .WillRepeatedly(Return(std::vector<Repository>{}));

    GitHubService service(gateway);
    
    service.listRepositories();
    service.listRepositories();
    service.listRepositories();
}