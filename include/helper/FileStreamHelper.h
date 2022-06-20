//
// Created by apenchev on 6/9/2022.
//

#ifndef SVG_PARSER_FILESTREAMHELPER_H
#define SVG_PARSER_FILESTREAMHELPER_H

#include <fstream>

class FileStreamHelper {
public:
    static char peekWithOffset(std::istream &in, unsigned int position = 1);

    static void skipWhitespaces(std::istream &in);
};


#endif //SVG_PARSER_FILESTREAMHELPER_H
