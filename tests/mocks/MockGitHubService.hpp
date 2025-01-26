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
 *	File : MockGitHubService.hpp
*/

#include <gmock/gmock.h>
#include <application/services/GitHubService.hpp>
#include <mocks/MockRepositoryGateway.hpp>


class MockGitHubService : public GitHubService {
public:
	
	MockGitHubService() : GitHubService(mockGateway) {};
MOCK_METHOD(std::vector<Repository>, listRepositories, (), (override));

private:
	MockRepositoryGateway mockGateway;
};