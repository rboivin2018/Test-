#pragma once

#include <domain/interfaces/IHttpClient.hpp>
#include <gmock/gmock.h>


class MockHttpClient : public IHttpClient {
public:

    MOCK_METHOD(std::string, sendRequest, (
        const std::string& url,
        const std::string& method,
        const std::string& data,
        const std::vector<std::string>& headers
    ), (override));
};