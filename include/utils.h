#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace utils {
    std::string generate_random_filename(const std::string& extension);
    bool is_valid_url(const std::string& url);
}

#endif // UTILS_H