#include <string>
#include <iostream>
#include "fdparser.h"
/*
 * This program copies files and directories' structure from in_dir to out_dir.
 * To make it happen, provide these paths to fdparser::parse static function.
 * !!! Make sure the folder you're copying to exists and it's empty.
 * Otherwise, std::filesystem throws an exception and the program terminates execution !!!
 */
int main() {
    std::string in_dir, out_dir;

    std::cout << "Initial path: " << std::endl;
    std::cin >> in_dir;
    std::cout << "Output path: " << std::endl;
    std::cin >> out_dir;

    fdparser::parse(in_dir, out_dir);
    return 0;
}
