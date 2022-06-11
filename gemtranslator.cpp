//
// Created by wrkhd on 6/7/22.
//

#include <fstream>
#include <regex>
#include <iostream>
#include "gemtranslator.h"

void gemtranslator::translate(const std::string& in_path, const std::string& out_path) {
    std::ifstream infile(in_path);
    std::ofstream outfile(out_path);
    // Array of strings representing tags in .gem file
    const std::string init_regex_array[7] = {"^# (.*)", "^## (.*)", "^### (.*)", "^\\* (.*)",
                                             "^=> (.*?) (.*)", "^> (.*)", "^[^<].*"};
    // Array of strings representing corresponding html tags
    const std::string substitute_regex_array[7] = {"<h1>$1</h1>", "<h2>$1</h2>", "<h3>$1</h3>","<li>$1</li>",
                                                   "<a href='$1'>$2</a>", "<blockquote>$1</blockquote>","<p>$0</p>"};

    if (infile.is_open() && outfile.is_open()) {
        std::string line;
        // Counter for <pre></pre> tagging
        int pre_count = 0;

        while (std::getline(infile, line)) {
            // Section responsible for correct translation of ``` tag (<pre></pre> in html)
            if(std::regex_match(line, std::regex("^```"))) {
                if(pre_count == 0) {
                    outfile << "<pre>" << std::endl;
                    pre_count++;
                    continue;
                }
                else if(pre_count == 1) {
                    outfile << "</pre>" << std::endl;
                    pre_count = 0;
                    continue;
                }
            }
            // If not inside a pre tag, translate as supposed to
            if(pre_count == 0) {
                for (int i = 0; i < 7; i++)
                    line = std::regex_replace(line, std::regex(init_regex_array[i]), substitute_regex_array[i]);
            }
            // If inside a pre tag, translate as raw text
            outfile << line << std::endl;
        }

        infile.close();
        outfile.close();

        // If file couldn't be opened, prints a message
    } else std::cout << "Couldn't parse .gem to .html - files are not available" << std::endl;
}

gemtranslator::gemtranslator() = default;
