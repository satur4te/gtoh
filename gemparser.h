//
// Created by wrkhd on 6/7/22.
//

#ifndef GEMTEXTTOHTML_GEMPARSER_H
#define GEMTEXTTOHTML_GEMPARSER_H

/*
 * Utility class that consists of only one method - parsing .gem file to .html
 */

#include <string>

class gemparser {

public:
    static void parse(const std::string& in_path, const std::string& out_path);
private:
    gemparser();
};


#endif //GEMTEXTTOHTML_GEMPARSER_H
