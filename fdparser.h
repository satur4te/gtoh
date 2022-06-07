//
// Created by wrkhd on 6/7/22.
//

#ifndef GEMTEXTTOHTML_FDPARSER_H
#define GEMTEXTTOHTML_FDPARSER_H

#include <string>

/*
 * Utility class that consists of only one method that copies files and directory structure by given paths
 * If faces *.gml, calls gemparses' parse method.
 */

class fdparser {

public:
    static void parse(const std::string& in_path, const std::string& out_path);
private:
    fdparser();
};


#endif //GEMTEXTTOHTML_FDPARSER_H
