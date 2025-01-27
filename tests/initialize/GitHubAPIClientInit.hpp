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
 *	File : GitHubAPITestInit.hpp
*/


#ifndef GITHUB_API_CLIENT_INIT_HPP
#define GITHUB_API_CLIENT_INIT_HPP

#include <gtest/gtest.h>

#include <mocks/MockHttpClient.hpp>

class GitHubAPIClientTestFixture : public ::testing::Test {
protected:
    std::unique_ptr<MockHttpClient> mockHttp;

    void SetUp() override {
        mockHttp = std::make_unique<MockHttpClient>();
    }
};

#endif // GITHUB_API_CLIENT_INIT_HPP