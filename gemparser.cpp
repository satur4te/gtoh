//
// Created by wrkhd on 6/7/22.
//

#include <fstream>
#include <regex>
#include <iostream>
#include "gemparser.h"
//"^```(.*)"

void gemparser::parse(const std::string& in_path, const std::string& out_path) {
    std::ifstream infile(in_path);
    std::ofstream outfile(out_path);
    const std::string init_regex_array[8] = {"^# (.*)", "^## (.*)", "^### (.*)", "^\\* (.*)",
                                             "^=> (.*?) (.*)", "^> (.*)", "^[^<].*"};

    const std::string substitute_regex_array[8] = {"<h1>$1</h1>", "<h2>$1</h2>", "<h3>$1</h3>","<li>$1</li>",
                                                   "<a href='$1'>$2</a>", "<blockquote>$1</blockquote>","<p>$0</p>"};

    if (infile.is_open() && outfile.is_open()) {
        std::string line;
        int pre_count = 0;

        while (std::getline(infile, line)) {

            if(std::regex_match(line, std::regex("^```(.*)"))) {
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

            if(pre_count == 0) {
                for (int i = 0; i < 7; i++)
                    line = std::regex_replace(line, std::regex(init_regex_array[i]), substitute_regex_array[i]);
            }

            outfile << line << std::endl;
        }

        infile.close();
        outfile.close();
    }
}

gemparser::gemparser() {

}
