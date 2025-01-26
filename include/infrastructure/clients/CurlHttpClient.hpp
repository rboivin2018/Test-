#include <domain/interfaces/IHttpClient.hpp>
#include <curl/curl.h>
#include <vector>

class CurlHttpClient : public IHttpClient {
public:
    CurlHttpClient();

    ~CurlHttpClient() override;

    std::string sendRequest(
        const std::string& url,
        const std::string& method,
        const std::string& data,
        const std::vector<std::string>& headers
    ) override;

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s);
};