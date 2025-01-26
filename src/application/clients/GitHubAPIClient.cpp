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

 * Date : 24/01/2025
 * Author: Remi Boivin
 *	File : GitHubAPIClient.cpp
*/

#include <application/clients/GitHubAPIClient.hpp>
#include <curl/curl.h>
#include <stdexcept>

GitHubAPIClient::GitHubAPIClient(std::unique_ptr<IHttpClient> httpClient, const std::string& token)
        : httpClient(std::move(httpClient)), token(token) {
        if (token.empty()) {
            throw std::invalid_argument("Token cannot be empty");
        }
    }

std::string GitHubAPIClient::sendRequest(const std::string& url, const std::string& method, const std::string& data) {
        if (url.empty()) {
            throw std::invalid_argument("URL cannot be empty");
        }
        
        if (method != "GET" && method != "POST" && method != "PUT" && method != "DELETE") {
            throw std::invalid_argument("Unsupported HTTP method");
        }

        std::vector<std::string> headers = {
            "Authorization: Bearer " + token,
            "User-Agent: GitHubAPILib",
            "Accept: application/vnd.github.v3+json",
            "Content-Type: application/json"
        };

        return httpClient->sendRequest(url, method, data, headers);
    }