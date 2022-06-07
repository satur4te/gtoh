#include <string>
#include <iostream>
#include "fdparser.h"

int main() {
    std::string in_dir, out_dir;
    //in_dir = "/home/wrkhd/Workspace/gemtexttohtml/testin";
    //out_dir = "/home/wrkhd/Workspace/gemtexttohtml/testout";
    std::cout << "Initial path: " << std::endl;
    std::cin >> in_dir;
    std::cout << "Output path: " << std::endl;
    std::cin >> out_dir;
    fdparser::parse(in_dir, out_dir);

    return 0;
}
