/*
 * Copyright (C) 2025 Remi Boivin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.

 * Date : 25/01/2025
 * Author: Remi Boivin
 *	File : GitHubAPIClientTests.hpp
*/

#include <mocks/MockHttpClient.hpp>
#include <infrastructure/clients/GitHubAPIClient.hpp>

using namespace testing;

TEST(GitHubAPIClientTest, SendGetRequestSuccess) {
    auto mockHttp = std::make_unique<MockHttpClient>();
    std::string expectedResponse = R"([{"id": 1, "name": "repo1"}])";

    EXPECT_CALL(*mockHttp, sendRequest(
        "https://api.github.com/user/repos",
        "GET",
        "",
        testing::Contains("Authorization: Bearer test_token")
    )).WillOnce(testing::Return(expectedResponse));

    GitHubAPIClient client(std::move(mockHttp), "test_token");
    auto response = client.sendRequest("https://api.github.com/user/repos", "GET", "");

    ASSERT_EQ(response, expectedResponse);
}

TEST(GitHubAPIClientTest, SendPostRequestSuccess) {
    auto mockHttp = std::make_unique<MockHttpClient>();
    std::string payload = R"({"name": "new-repo"})";
    std::string expectedResponse = R"({"id": 123, "name": "new-repo"})";

    EXPECT_CALL(*mockHttp, sendRequest(
        "https://api.github.com/user/repos",
        "POST",
        payload,
        testing::Contains("Authorization: Bearer test_token")
    )).WillOnce(testing::Return(expectedResponse));

    GitHubAPIClient client(std::move(mockHttp), "test_token");
    auto response = client.sendRequest("https://api.github.com/user/repos", "POST", payload);

    ASSERT_EQ(response, expectedResponse);
}

TEST(GitHubAPIClientTest, HandleNetworkError) {
    auto mockHttp = std::make_unique<MockHttpClient>();

    EXPECT_CALL(*mockHttp, sendRequest(
        testing::_,
        testing::_,
        testing::_,
        testing::_
    )).WillOnce(testing::Throw(std::runtime_error("Network error")));

    GitHubAPIClient client(std::move(mockHttp), "test_token");

    EXPECT_THROW({
        client.sendRequest("https://api.github.com/user/repos", "GET", "");
    }, std::runtime_error);
}

TEST(GitHubAPIClientTest, SendRequestWithInvalidToken) {
    auto mockHttp = std::make_unique<MockHttpClient>();

    EXPECT_CALL(*mockHttp, sendRequest(
        testing::_,
        testing::_,
        testing::_,
        testing::Contains("Authorization: Bearer invalid_token")
    )).WillOnce(testing::Return("Unauthorized"));

    GitHubAPIClient client(std::move(mockHttp), "invalid_token");
    auto response = client.sendRequest("https://api.github.com/user/repos", "GET", "");

    ASSERT_EQ(response, "Unauthorized");
}

TEST(GitHubAPIClientTest, SendRequestWithUnsupportedMethod) {
    auto mockHttp = std::make_unique<MockHttpClient>();

    GitHubAPIClient client(std::move(mockHttp), "test_token");

    EXPECT_THROW({
        client.sendRequest("https://api.github.com/user/repos", "PATCH", "");
    }, std::invalid_argument);
}

TEST(GitHubAPIClientTest, SendRequestWithEmptyUrl) {
    auto mockHttp = std::make_unique<MockHttpClient>();

    GitHubAPIClient client(std::move(mockHttp), "test_token");

    EXPECT_THROW({
        client.sendRequest("", "GET", "");
    }, std::invalid_argument);
}

TEST(GitHubAPIClientTest, SendRequestWithCustomHeaders) {
    auto mockHttp = std::make_unique<MockHttpClient>();

    EXPECT_CALL(*mockHttp, sendRequest(
        testing::_,
        testing::_,
        testing::_,
        testing::AllOf(
            testing::Contains("Authorization: Bearer test_token"),
            testing::Contains("User-Agent: GitHubAPILib"),
            testing::Contains("Accept: application/vnd.github.v3+json")
        )
    )).WillOnce(testing::Return("OK"));

    GitHubAPIClient client(std::move(mockHttp), "test_token");
    auto response = client.sendRequest("https://api.github.com/user/repos", "GET", "");

    ASSERT_EQ(response, "OK");
}

TEST(GitHubAPIClientTest, SendDeleteRequestSuccess) {
    auto mockHttp = std::make_unique<MockHttpClient>();
    std::string expectedResponse = R"({"status": "deleted"})";

    EXPECT_CALL(*mockHttp, sendRequest(
        "https://api.github.com/repos/user/repo",
        "DELETE",
        "",
        testing::_
    )).WillOnce(testing::Return(expectedResponse));

    GitHubAPIClient client(std::move(mockHttp), "test_token");
    auto response = client.sendRequest("https://api.github.com/repos/user/repo", "DELETE", "");

    ASSERT_EQ(response, expectedResponse);
}

TEST(GitHubAPIClientTest, SendRequestWithEmptyToken) {
    auto mockHttp = std::make_unique<MockHttpClient>();
    
    EXPECT_THROW({
        GitHubAPIClient client(std::move(mockHttp), "");
        client.sendRequest("https://api.github.com/user/repos", "GET", "");
    }, std::invalid_argument);
}