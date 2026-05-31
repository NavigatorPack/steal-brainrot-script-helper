#ifndef ROBLOX_SCRIPT_STEALER_H
#define ROBLOX_SCRIPT_STEALER_H

#include <string>
#include <vector>

class RobloxScriptStealer {
public:
    static std::string fetch_script(const std::string& script_url);
    static bool save_script(const std::string& script_content, const std::string& output_path);
    static std::vector<std::string> extract_script_urls(const std::string& page_content);
};

#endif // ROBLOX_SCRIPT_STEALER_H