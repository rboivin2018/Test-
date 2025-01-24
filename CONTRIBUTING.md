# Contributing to GitHub API Library in C++

Thank you for your interest in contributing to the GitHub API Library in C++! We welcome contributions from the community to help improve and expand this project. Whether you're fixing bugs, adding features, or improving documentation, your contributions are highly appreciated.

Please take a moment to review this document to ensure a smooth and collaborative contribution process.

---

## Table of Contents

1. [Getting Started](#getting-started)
2. [Code of Conduct](#code-of-conduct)
3. [How to Contribute](#how-to-contribute)
   - [Reporting Bugs](#reporting-bugs)
   - [Suggesting Enhancements](#suggesting-enhancements)
   - [Submitting Pull Requests](#submitting-pull-requests)
4. [Development Setup](#development-setup)
5. [Coding Guidelines](#coding-guidelines)
6. [Testing](#testing)
7. [Commit Message Guidelines](#commit-message-guidelines)
8. [License](#license)

---

## Getting Started

Before contributing, please ensure you have the following installed:

- **C++ Compiler** : GCC, Clang, or MSVC.
- **libcurl** : For HTTP requests.
- **nlohmann/json** : For JSON parsing.
- **Git** : For version control.

---

## Code of Conduct

By participating in this project, you agree to abide by our [Code of Conduct](CODE_OF_CONDUCT.md). Please read it to understand the expected behavior and how to report any issues.

---

## How to Contribute

### Reporting Bugs

If you find a bug, please open an issue on GitHub and provide the following information:

1. **Description** : A clear and concise description of the bug.
2. **Steps to Reproduce** : Detailed steps to reproduce the issue.
3. **Expected Behavior** : What you expected to happen.
4. **Actual Behavior** : What actually happened.
5. **Screenshots/Logs** : If applicable, include screenshots or logs to help explain the issue.
6. **Environment** : Your operating system, compiler version, and library versions.

### Suggesting Enhancements

If you have an idea for a new feature or improvement, please open an issue on GitHub and provide the following information:

1. **Description** : A clear and concise description of the enhancement.
2. **Use Case** : Explain why this enhancement is useful and how it would be used.
3. **Proposed Solution** : If you have a solution in mind, describe it briefly.

### Submitting Pull Requests

To contribute code, follow these steps:

1. **Fork the Repository** : Fork the repository to your GitHub account.
2. **Create a Branch** : Create a new branch for your feature or bug fix.
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Make Changes** : Implement your changes and ensure they follow the [Coding Guidelines](#coding-guidelines).
4. **Test Your Changes** : Run tests to ensure your changes work as expected.
5. **Commit Your Changes** : Write clear and descriptive commit messages.
6. **Push Your Changes** : Push your branch to your forked repository.
   ```bash
   git push origin feature/your-feature-name
   ```
7. **Open a Pull Request** : Open a pull request (PR) against the `master` branch of the original repository. Provide a clear description of your changes and reference any related issues.

---

## Development Setup


## Coding Guidelines

- Follow the **Clean Architecture** principles.
- Use meaningful variable and function names.
- Write comments to explain complex logic.
- Keep functions small and focused on a single responsibility.
- Lint your code before create a pull request.
- Follow the C++ Core Guidelines where applicable.

---

## Testing

- Write unit tests for new features and bug fixes.
- Use **Catch2**.
- Ensure all tests pass before submitting a pull request.

Example test with Catch2:
```cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "domain/entities/Repository.hpp"

TEST_CASE("Repository entity", "[repository]") {
    Repository repo{"test-repo", "https://github.com/user/test-repo", "A test repository", false};
    REQUIRE(repo.name == "test-repo");
    REQUIRE(repo.url == "https://github.com/user/test-repo");
}
```

---

## Commit Message Guidelines

- Use the present tense ("Add feature" instead of "Added feature").
- Use the imperative mood ("Fix bug" instead of "Fixes bug").
- Keep the subject line under 50 characters.
- Provide a detailed body if necessary, explaining the "why" and "how" of the change.
- Follow the [conventional guidelines](https://www.conventionalcommits.org/en/v1.0.0/)

Example:
```
feat: Add support for listing repositories

This commit adds a new method to list repositories using the GitHub API.
The method retrieves the list of repositories for the authenticated user
and returns them as a vector of Repository objects.
```

---

## License

By contributing to this project, you agree that your contributions will be licensed under the [GNU License](LICENSE).

---

Thank you for contributing to the GitHub API Library in C++! Your efforts help make this project better for everyone. 🚀
```