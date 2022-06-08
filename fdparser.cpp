#include <string>
#include <filesystem>
#include <regex>
#include "gemtranslator.h"
#include "fdparser.h"

void fdparser::parse(const std::string &in_path, const std::string &out_path) {
    for (const auto &entry : std::filesystem::recursive_directory_iterator(in_path)) {
        // Local in_path and local out_path for an iteration
        std::string linpath = entry.path();
        std::string loutpath = std::regex_replace(linpath,std::regex(in_path), out_path);

        // Creates corresponding directories
        if(entry.is_directory()) {
            std::filesystem::create_directory(loutpath);
        }

        if(entry.is_regular_file()) {
            // If a file has .gmi extension, call gemtranslator::translate.
            if(std::regex_match(linpath, std::regex("(.*)\\.gmi$"))) {
                gemtranslator::translate(linpath, loutpath.replace(loutpath.end() - 3, loutpath.end(), "html"));
                // If a file doesn't have .gmi extension, it just gets copied.
            } else std::filesystem::copy_file(linpath, loutpath);
        }
    }
}

fdparser::fdparser() = default;
