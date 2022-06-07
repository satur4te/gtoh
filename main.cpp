#include <string>
#include <iostream>
#include <filesystem>
#include <regex>
#include "gemparser.h"
#include "fdparser.h"

namespace fs = std::filesystem;

int main() {
    std::string in_dir, out_dir;
    in_dir = "/home/wrkhd/Workspace/gemtexttohtml/testin";
    out_dir = "/home/wrkhd/Workspace/gemtexttohtml/testout";
    std::cout << "Initial path: " << std::endl;
    //std::cin >> in_dir;
    std::cout << "Output path: " << std::endl;
    //std::cin >> out_dir;
    fdparser::parse("/home/wrkhd/Workspace/gemtexttohtml/testin", "/home/wrkhd/Workspace/gemtexttohtml/testout");
    // gemparser::parse("/home/wrkhd/Workspace/1.gmi", "/home/wrkhd/Workspace/1.html");

    return 0;
}
