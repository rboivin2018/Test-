# GitHub API Library in C++

A C++ library for interacting with the GitHub API, enabling listing, creating, and managing repositories. This project follows **Clean Architecture** principles for better modularity, testability, and maintainability.

---

## Features

|Feature|Description|
|-------|-----------|
|**List repositories**| Retrieve the list of repositories for the authenticated user.|
|**Create a repository**|Create a new repository on GitHub.|
|**Delete repositories**|Delete an existing repository.|

---

## Roadmap

- v1.0.0
	- **List issues:** Retrieve the list of issues for the repository.
	- **Create an issue:** Create a new issue on GitHub.
	- **Retrieve an issue:** Retrieve the issue's content
	- **Delete issues:** Delete an existing issue.

- v1.1.0
	- **List projects:** Retrieve the list of projects for the user.
	- **Create an project:** Create a new project on GitHub.
	- **Retrieve an project:** Retrieve the project's content
	- **Delete projects:** Delete an existing issue.

---

## Prerequisites

- **C++ Compiler** : GCC, Clang, or MSVC.
- **libcurl** : For HTTP requests.
- **nlohmann/json** : For JSON parsing.
- **GitHub Access Token** : A personal access token with `repo` permissions.

---

## Installation

### Clone the Repository
```bash
git clone https://github.com/rboivin2018/github-lib.git
cd github-lib
```

### Install Dependencies
- **On Linux (Debian/Ubuntu)** :
  ```bash
  sudo apt update
  sudo apt install libcurl4-openssl-dev
  ```

- **On macOS (with Homebrew)** :
  ```bash
  brew install curl
  ```

- **nlohmann/json** :
```bash
  sudo apt install nlohmann-json
  ```

### Build the Library
```bash
mkdir build
cd build
cmake ../
make
sudo make install
```
---

## Usage

### Set Up GitHub Token
Export your GitHub token as an environment variable:
```bash
export GITHUB_TOKEN="your_github_token"
```

### Integrate the Library
Include the library in your C++ project and use it as follows:

```cpp
#include "infrastructure/clients/GitHubAPIClient.hpp"
#include "application/services/GitHubService.hpp"

int main() {
    std::string token = "your_github_token";
    GitHubAPIClient apiClient(token);
    GitHubService service(apiClient);

    // List repositories
    auto repos = service.listRepositories();
    for (const auto& repo : repos) {
        std::cout << "Repository: " << repo.name << " - " << repo.url << std::endl;
    }

    return 0;
}
```

## Contributing

Contributions are welcome! Here’s how to contribute:

1. **Fork the project**.
2. Create a feature branch (`git checkout -b feature/new-feature`).
3. Commit your changes (`git commit -m 'Add a new feature'`).
4. Push the branch (`git push origin feature/new-feature`).
5. Open a **Pull Request**.

See the [CONTRIBUTING](CONTRIBUTING.md) file for details.

---

## License

This project is licensed under the GNU License. See the [LICENSE](LICENSE) file for details.

---

## Author

- **Rémi Boivin** - [rboivin2018](https://github.com/rboivin2018)

---