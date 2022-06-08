//
// Created by wrkhd on 6/7/22.
//

#ifndef GEMTEXTTOHTML_GEMTRANSLATOR_H
#define GEMTEXTTOHTML_GEMTRANSLATOR_H

/*
 * Utility class that consists of only one function that translates .gem file to .html.
 * The function reads the file by in_path and writes translated html text to a file by out_path.
 */

#include <string>

// .gem parser
class gemtranslator {

public:
    static void translate(const std::string& in_path, const std::string& out_path);
private:
    // Making sure we cannot instance the utility class
    gemtranslator();
};


#endif //GEMTEXTTOHTML_GEMTRANSLATOR_H
