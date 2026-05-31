#include "utils.h"
#include <random>
#include <algorithm>

std::string utils::generate_random_filename(const std::string& extension) {
    const std::string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string filename;
    for (int i = 0; i < 10; ++i) {
        filename += chars[dist(generator)];
    }
    return filename + extension;
}

bool utils::is_valid_url(const std::string& url) {
    return url.find("http://") == 0 || url.find("https://") == 0;
}