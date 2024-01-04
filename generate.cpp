#include <iostream>
#include <bitset>
#include "generate.h"

std::string toBits(int num) {
    std::string binary = std::bitset<NUM_BITS>(num).to_string(); //to binary
    return binary;
}

std::string trimZeros(std::string bits) {
    bits = bits.substr(bits.find_first_of('1'), NUM_BITS - 1);

    // std::cout << bits << std::endl;
    return bits;
}