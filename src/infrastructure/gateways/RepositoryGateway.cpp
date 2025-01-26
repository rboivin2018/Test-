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
 *	File : RepositoryGateway.cpp
*/

#include <infrastructure/gateways/RepositoryGateway.hpp>
#include <nlohmann/json.hpp>


RepositoryGateway::RepositoryGateway(const std::string& token, std::string username) : client(token), username(username) {}

std::vector<Repository> RepositoryGateway::listRepositories() {
    std::string url = "https://api.github.com/" + username + "/repos";
    std::string response = client.sendRequest(url);
    auto jsonResponse = nlohmann::json::parse(response);

std::vector<Repository> repos;

for (const auto& repo : jsonResponse) {
        repos.push_back({
            repo["name"],
            repo["html_url"],
				repo["description"],
				repo["private"]
        });
    }
    return repos;
}