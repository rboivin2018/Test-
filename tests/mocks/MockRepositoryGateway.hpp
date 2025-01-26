#ifndef MOCK_REPOSITORY_GATEWAY_HPP
#define MOCK_REPOSITORY_GATEWAY_HPP

#include <domain/interfaces/IRepositoryGateway.hpp>
#include <gmock/gmock.h>

class MockRepositoryGateway : public IRepositoryGateway {
public:
    MOCK_METHOD(std::vector<Repository>, listRepositories, (), (override));
};

#endif // MOCK_REPOSITORY_GATEWAY_HPP