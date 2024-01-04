#ifndef GENERATE_H_
#define GENERATE_H_

#include <bitset>

constexpr int NUM_BITS = 16;

std::string toBits(int num);
std::string trimZeros(std::string bits);

#endif