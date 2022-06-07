#include <string>
#include <iostream>
#include <filesystem>
#include <regex>
#include "gemparser.h"
namespace fs = std::filesystem;

int main() {
    std::string in_dir, out_dir;

    /*
    std::cout << "Initial path: " << std::endl;
    std::cin >> in_dir;
    std::cout << "Output path: " << std::endl;
    std::cin >> out_dir;
    */

    std::string path = "/home/wrkhd/Workspace";
    for (const auto & entry : fs::recursive_directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
        }

    gemparser::parse("/home/wrkhd/Workspace/1.gmi", "/home/wrkhd/Workspace/1.html");
    return 0;
}
