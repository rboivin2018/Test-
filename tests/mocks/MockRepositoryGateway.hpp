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

 * Date : 26/01/2025
 * Author: Remi Boivin
 *	File : MockRepositoryGateway.hpp
*/

#ifndef MOCK_REPOSITORY_GATEWAY_HPP
#define MOCK_REPOSITORY_GATEWAY_HPP

#include <domain/interfaces/IRepositoryGateway.hpp>
#include <gmock/gmock.h>

class MockRepositoryGateway : public IRepositoryGateway {
public:
    MOCK_METHOD(std::vector<Repository>, listRepositories, (), (override));
};

#endif // MOCK_REPOSITORY_GATEWAY_HPP