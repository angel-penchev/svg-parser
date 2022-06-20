//
// Created by apenchev on 5/28/2022.
//

#include "../../include/program/Program.h"
#include "../../include/helper/String.h"

int Program::run() {
    String command;
    while (std::cout << "|> " && std::cin >> command) {
        // Command for printing all the SVG shapes
        if (command == "print") {
            Program::printCommand();
            continue;
        }

        // Command for exiting the program
        if (command == "exit") {
            break;
        }
    }

    std::cout << '\n';

    return 0;
}

void Program::printCommand() {

}

void Program::createCommand() {

}

void Program::eraseCommand() {

}

void Program::translateCommand() {

}

void Program::withinCommand() {

}