#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <algorithm>

namespace fs = std::filesystem;

std::string get_next_day_folder(const std::string& base_dir) {
    std::regex day_regex("day(\\d{2})");
    int max_day = 0;

    for (const auto& entry : fs::directory_iterator(base_dir)) {
        if (entry.is_directory()) {
            std::smatch match;
            std::string name = entry.path().filename().string();
            if (std::regex_match(name, match, day_regex)) {
                int day_num = std::stoi(match[1]);
                max_day = std::max(max_day, day_num);
            }
        }
    }

    char next_day[16];
    std::sprintf(next_day, "day%02d", max_day + 1);
    return std::string(next_day);
}

void create_solution_files(const fs::path& day_dir) {
    fs::create_directories(day_dir);

    std::ofstream cpp_file(day_dir / "solution.cpp");
    cpp_file << "#include \"solution.hpp\"\n";
    cpp_file.close();

    std::ofstream hpp_file(day_dir / "solution.hpp");
    hpp_file << "#pragma once\n\n";
    hpp_file.close();

    std::ofstream readme_file(day_dir / "README.md");
    readme_file << "# " << day_dir.filename().string() << "\n\n"
                << "## Problem\n(Describe the problem here)\n\n"
                << "## Notes\n(Add any thoughts, optimizations, or learnings)\n";
    readme_file.close();
}

void create_test_file(const std::string& day_name) {
    fs::create_directories("tests");

    std::ofstream test_file("tests/" + day_name + "_test.cpp");
    test_file.close();  // Empty test file
}

int main() {
    const std::string base_dir = "days";
    if (!fs::exists(base_dir)) {
        fs::create_directory(base_dir);
    }

    std::string next_day = get_next_day_folder(base_dir);
    fs::path day_path = fs::path(base_dir) / next_day;

    create_solution_files(day_path);
    create_test_file(next_day);

    std::cout << "✅ Created " << day_path << " with empty solution files and test" << std::endl;

    return 0;
}
