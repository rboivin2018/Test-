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
 *	File : GitHubCLI.cpp
*/

#include <presentation/cli/GitHubCLI.hpp>
#include <iostream>


GitHubCLI::GitHubCLI(IGitHubService& service) : service(service) {}

void GitHubCLI::run() {
    std::cout << "GitHub CLI\n";
    std::cout << "1. List Repositories\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            auto repos = service.listRepositories();
            for (const auto& repo : repos) {
                std::cout << "Name: " << repo.name << ", URL: " << repo.url << "\n";
            }
            break;
        }
        default:
            std::cout << "Invalid option!\n";
    }
}