//
// Created by apenchev on 6/9/2022.
//

#include "../../include/helper/FileStreamHelper.h"

char FileStreamHelper::peekWithOffset(std::istream &in, unsigned int position) {
    char readBuffer;
    unsigned int startPosition = in.tellg();

    // Seek to 1 position before the requested character
    in.seekg(position - 1, std::ios::cur);

    // Read the next position - the requested character
    in.read(&readBuffer, 1);

    // Return to the starting position
    in.seekg(startPosition, std::ios::beg);

    return readBuffer;
}
