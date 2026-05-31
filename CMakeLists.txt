cmake_minimum_required(VERSION 3.10)
project(steal_brainrot_script_helper)

set(CMAKE_CXX_STANDARD 17)

add_executable(steal_brainrot_script_helper
    src/main.cpp
    src/roblox_script_stealer.cpp
    src/utils.cpp
)

target_include_directories(steal_brainrot_script_helper PRIVATE include)
target_link_libraries(steal_brainrot_script_helper PRIVATE curl)