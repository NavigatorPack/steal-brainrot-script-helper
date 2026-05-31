#include <iostream>
#include "roblox_script_stealer.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <script_url_or_page_url>" << std::endl;
        return 1;
    }

    std::string input_url = argv[1];
    if (!utils::is_valid_url(input_url)) {
        std::cerr << "Invalid URL provided." << std::endl;
        return 1;
    }

    std::string script_content;
    if (input_url.find("/scripts/") != std::string::npos) {
        script_content = RobloxScriptStealer::fetch_script(input_url);
    } else {
        std::string page_content = RobloxScriptStealer::fetch_script(input_url);
        auto script_urls = RobloxScriptStealer::extract_script_urls(page_content);
        if (script_urls.empty()) {
            std::cerr << "No scripts found on the page." << std::endl;
            return 1;
        }
        script_content = RobloxScriptStealer::fetch_script(script_urls[0]);
    }

    if (script_content.empty()) {
        std::cerr << "Failed to fetch script content." << std::endl;
        return 1;
    }

    std::string output_filename = utils::generate_random_filename(".lua");
    if (!RobloxScriptStealer::save_script(script_content, output_filename)) {
        std::cerr << "Failed to save script to file." << std::endl;
        return 1;
    }

    std::cout << "Successfully saved script to: " << output_filename << std::endl;
    return 0;
}