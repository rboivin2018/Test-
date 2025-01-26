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
 *	File : IRepositoryGateway.hpp
*/

#ifndef I_REPOSITORY_GATEWAY_HPP
#define I_REPOSITORY_GATEWAY_HPP

#include <vector>
#include <domain/entities/Repository.hpp>

class IRepositoryGateway {
public:
    virtual ~IRepositoryGateway() = default;
    virtual std::vector<Repository> listRepositories() = 0;
};

#endif // IREPOSITORYGATEWAY_HPP