#include <presentation/cli/GitHubCLI.hpp>
#include <application/services/GitHubService.hpp>
#include <infrastructure/gateways/RepositoryGateway.hpp>

int main() {
    std::string token = "";
    RepositoryGateway gateway(token, "rboivin2018");
    GitHubService service(gateway);
    GitHubCLI cli(service);

    cli.run();

    return 0;
}