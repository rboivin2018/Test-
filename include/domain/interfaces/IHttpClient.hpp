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

#ifndef I_HTTP_CLIENT_HPP
#define I_HTTP_CLIENT_HPP

#include <string>
#include <functional>

class IHttpClient {
public:
    virtual ~IHttpClient() = default;
    
    virtual std::string sendRequest(
        const std::string& url,
        const std::string& method,
        const std::string& data,
        const std::vector<std::string>& headers
    ) = 0;
};

#endif // I_HTTP_CLIENT_HPP