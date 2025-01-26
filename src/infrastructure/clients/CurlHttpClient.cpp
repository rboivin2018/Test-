#include <stdexcept>
#include <curl/curl.h>
#include <vector>

#include <infrastructure/clients/CurlHttpClient.hpp>

CurlHttpClient::CurlHttpClient() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }

CurlHttpClient::~CurlHttpClient() {
        curl_global_cleanup();
    }

std::string CurlHttpClient::sendRequest(
        const std::string& url,
        const std::string& method,
        const std::string& data,
        const std::vector<std::string>& headers
    ) {
        CURL* curl = curl_easy_init();
        std::string response;
        struct curl_slist* curl_headers = nullptr;

        try {
            if(!curl) throw std::runtime_error("CURL initialization failed");

            // Configuration des headers
            for(const auto& header : headers) {
                curl_headers = curl_slist_append(curl_headers, header.c_str());
            }

            // Configuration CURL
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_headers);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            if(method == "POST" || method == "PUT") {
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            }

            CURLcode res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                throw std::runtime_error(curl_easy_strerror(res));
            }

            curl_slist_free_all(curl_headers);
            curl_easy_cleanup(curl);
            
            return response;

        } catch(...) {
            curl_slist_free_all(curl_headers);
            curl_easy_cleanup(curl);
            throw;
        }
    }

size_t CurlHttpClient::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
        size_t newLength = size * nmemb;
        try {
            s->append((char*)contents, newLength);
            return newLength;
        } catch(...) {
            return 0;
        }
    }