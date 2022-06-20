//
// Created by apenchev on 5/28/2022.
//

#include "../../include/program/Program.h"

int Program::run() {
    String command;
    Svg *svg = nullptr;
    while (std::cout << "|> " && std::cin >> command && std::cin.ignore()) {
        // Command for opening an SVG file
        if (command == "open") {
            Program::openCommand(&svg);
            continue;
        }

        // Command for closing an SVG file
        if (command == "close") {
            Program::closeCommand(&svg);
            continue;
        }

        // Command for printing all the SVG shapes
        if (command == "print") {
            Program::printCommand(&svg);
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

void Program::openCommand(Svg **svg) {
    // User input for filename
    char filename[MAX_STR_LEN];
    std::cin >> filename;

    // Verify no other file is open
    if (*svg != nullptr) {
        std::cerr << "ERR: There is a file already open.";
        return;
    }

    try {
        // Create DomDocument and SVG from filename
        *svg = new Svg(*(new DomDocument(filename))); // I have sinned, but there is no time to fix
        std::cout << "Successfully opened " << filename << ".\n";
    } catch (const std::exception &exception) {
        std::cerr << "ERR: " << exception.what() << '\n';
        return;
    }
}

void Program::closeCommand(Svg **svg) {
    if (svg == nullptr) {
        std::cerr << "ERR: No file is currently open.\n";
        return;
    }

    // Delete SVG without saving.
    String filename = (*svg)->getDocument().getFilename();
    delete *svg;
    *svg = nullptr;
    std::cout << "Successfully closed " << filename << ".\n";
}

void Program::printCommand(Svg **svg) {
}

void Program::createCommand(Svg **svg) {

}

void Program::eraseCommand(Svg **svg) {

}

void Program::translateCommand(Svg **svg) {

}

void Program::withinCommand(Svg **svg) {

}
