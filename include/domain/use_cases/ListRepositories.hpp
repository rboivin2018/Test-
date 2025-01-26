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
 *	File : ListRepositories.hpp
*/

#ifndef LIST_REPOSITORIES_HPP
#define LIST_REPOSITORIES_HPP

#include <vector>
#include <domain/entities/Repository.hpp>
#include <domain/interfaces/IRepositoryGateway.hpp>

class ListRepositoriesUseCase {
public:
    ListRepositoriesUseCase(IRepositoryGateway& gateway);
    std::vector<Repository> execute();

private:
    IRepositoryGateway& gateway;
};

#endif // LIST_REPOSITORIES_HPP