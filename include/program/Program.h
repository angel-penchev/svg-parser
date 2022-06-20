//
// Created by apenchev on 5/28/2022.
//

#ifndef SVG_PARSER_PROGRAM_H
#define SVG_PARSER_PROGRAM_H

#include <iostream>
#include <cstring>

#define MAX_CMD_LEN 128

class Program {
private:
public:
    static int run();

    static void printCommand();

    void createCommand();

    void eraseCommand();

    void translateCommand();

    void withinCommand();
};


#endif //SVG_PARSER_PROGRAM_H
