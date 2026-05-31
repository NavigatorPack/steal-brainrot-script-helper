#include "roblox_script_stealer.h"
#include <curl/curl.h>
#include <regex>
#include <fstream>
#include <sstream>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

std::string RobloxScriptStealer::fetch_script(const std::string& script_url) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, script_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            response.clear();
        }
        curl_easy_cleanup(curl);
    }
    return response;
}

bool RobloxScriptStealer::save_script(const std::string& script_content, const std::string& output_path) {
    std::ofstream out_file(output_path);
    if (!out_file.is_open()) {
        return false;
    }
    out_file << script_content;
    out_file.close();
    return true;
}

std::vector<std::string> RobloxScriptStealer::extract_script_urls(const std::string& page_content) {
    std::vector<std::string> script_urls;
    std::regex script_regex(R"(https?://[^\s"']+/scripts/[^\s"']+\.lua)");
    std::smatch matches;

    std::string::const_iterator search_start(page_content.cbegin());
    while (std::regex_search(search_start, page_content.cend(), matches, script_regex)) {
        script_urls.push_back(matches[0]);
        search_start = matches[0].second;
    }

    return script_urls;
}