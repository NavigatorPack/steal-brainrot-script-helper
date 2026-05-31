#include <gtest/gtest.h>
#include "roblox_script_stealer.h"
#include "utils.h"

TEST(RobloxScriptStealerTest, ExtractScriptUrls) {
    std::string test_content = R"(
        <a href="https://example.com/scripts/test1.lua">Script 1</a>
        <a href="https://example.com/scripts/test2.lua">Script 2</a>
        <a href="invalid_url">Invalid</a>
    )";

    auto urls = RobloxScriptStealer::extract_script_urls(test_content);
    ASSERT_EQ(urls.size(), 2);
    EXPECT_EQ(urls[0], "https://example.com/scripts/test1.lua");
    EXPECT_EQ(urls[1], "https://example.com/scripts/test2.lua");
}

TEST(UtilsTest, GenerateRandomFilename) {
    std::string filename = utils::generate_random_filename(".lua");
    EXPECT_EQ(filename.size(), 14);
    EXPECT_EQ(filename.substr(10), ".lua");
}

TEST(UtilsTest, ValidateUrl) {
    EXPECT_TRUE(utils::is_valid_url("https://example.com"));
    EXPECT_TRUE(utils::is_valid_url("http://example.com"));
    EXPECT_FALSE(utils::is_valid_url("example.com"));
    EXPECT_FALSE(utils::is_valid_url("ftp://example.com"));
}