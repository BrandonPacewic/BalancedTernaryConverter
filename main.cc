/*
 * Copyright (c) 2022 Brandon Pacewic
 *
 * Developed and tested by Brandon Pacewic
 * 
 * main test file for balanced ternary converter
 */


#include "src/balanced_ternary_converter.h"

// TODO: Add seperate compilation
// Acounting for no seperate compilation
#ifndef _BALANCED_TERNARY_CONVERTER_C
#include "src/balanced_ternary_converter.cc"
#endif

#include <iostream>
#include <string>

int main() {
    int value;
    std::cin >> value;

    std::string result = ternary::balanced_convert(value);
    std::cout << result << '\n';

    return 0;
}