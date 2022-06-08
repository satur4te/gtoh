//
// Created by wrkhd on 6/7/22.
//

#ifndef GEMTEXTTOHTML_FDPARSER_H
#define GEMTEXTTOHTML_FDPARSER_H

#include <string>

/*
 * Utility class that consists of only one function that copies files and directories' structure by given paths.
 * If faces *.gml, calls gemtranslator::translate function.
 * It is assumed that out_path is an existing empty folder, otherwise program fails.
 */

// file-directory parser
class fdparser {

public:
    static void parse(const std::string& in_path, const std::string& out_path);
private:
    // Making sure we cannot instance the utility class
    fdparser();
};


#endif //GEMTEXTTOHTML_FDPARSER_H
