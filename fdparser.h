//
// Created by wrkhd on 6/7/22.
//

#ifndef GEMTEXTTOHTML_FDPARSER_H
#define GEMTEXTTOHTML_FDPARSER_H

#include <string>

/*
 * Utility class that copies files and directory structure by given paths
 * If faces *.gml, calls gemparses' parse method.
 */

class fdparser {

public:
    static void parse(std::string in_dir, std::string out_dir);
};


#endif //GEMTEXTTOHTML_FDPARSER_H
