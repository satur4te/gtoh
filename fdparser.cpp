#include <string>
#include <iostream>
#include <filesystem>
#include <regex>
#include "gemparser.h"
#include "fdparser.h"

namespace fs = std::filesystem;

void fdparser::parse(const std::string &in_path, const std::string &out_path) {
    for (const auto & entry : fs::recursive_directory_iterator(in_path)) {
        std::string linpath = entry.path();
        std::string loutpath = std::regex_replace(linpath,std::regex(in_path), out_path);

        if(entry.is_directory()) {
            fs::create_directory(loutpath);
        }

        if(entry.is_regular_file()) {
            if(std::regex_match(linpath, std::regex("(.*)\\.gmi$"))) {
                gemparser::parse(linpath, loutpath.replace(loutpath.end() - 3, loutpath.end(), "html"));
            }
            else fs::copy_file(linpath, loutpath);
        }
    }
}

fdparser::fdparser() {

}
