//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_PROGRAM_H
#define SVG_PARSER_PROGRAM_H

#include <iostream>
#include <cstring>
#include "../svg/Svg.h"

class Program {
private:
public:
    static int run();

    static void openCommand(Svg **svg);

    static void closeCommand(Svg **svg);

    static void saveCommand(Svg **svg);

    static void saveAsCommand(Svg **svg);

    static void printCommand(Svg **svg);

    static void createCommand(Svg **svg);

    static void eraseCommand(Svg **svg);

    static void translateCommand(Svg **svg);

    static void withinCommand(Svg **svg);
};


#endif //SVG_PARSER_PROGRAM_H
