// Copyright (c) Brandon Pacewic
// SPDX-License-Identifier: MIT

#include "balanced_ternary_converter.h"

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a number: ";

    int value;
    std::cin >> value;

    std::string result = ternary::balanced_convert(value);
    std::cout << result << '\n';

    return 0;
}