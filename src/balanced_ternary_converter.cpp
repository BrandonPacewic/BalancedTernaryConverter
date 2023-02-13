// Copyright (c) Brandon Pacewic
// SPDX-License-Identifier: MIT

#include "balanced_ternary_converter.h"

#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

namespace ternary {
namespace {

std::vector<int> initalize_values(const int &value) {
    std::vector<int> values;

    for (int i = 0; pow(3, i) <= value; ++i) {
        values.push_back(pow(3, i));
    }

    std::reverse(values.begin(), values.end());

    return values;
}

std::vector<int> make_ternary(const std::vector<int> &values, int value) {
    std::vector<int> ternary(values.size(), 0);

    for (std::size_t i = 0; i < values.size(); ++i) {
        ternary[i] += value / values[i];
        value %= values[i];
    }
    std::reverse(ternary.begin(), ternary.end());

    return ternary;
}

void convert_to_balanced(std::vector<int> &ternary) {
    for (int i = 0; i < ternary.size(); ++i) {
        if (ternary[i] > 1 && i + 1 >= ternary.size()) ternary.push_back(0);
        if (ternary[i] == 3) {
            ternary[i] = 0;
            ++ternary[i + 1];
        } else if (ternary[i] == 2) {
            ternary[i] = -1;
            ++ternary[i + 1];
        }
    }
}

std::string convert_to_symbols(const std::vector<int> &balanced_ternary,
                               const bool &invert_signs) {
    std::string symbols(balanced_ternary.size(), '0');

    auto redirected_balanced_ternary = balanced_ternary;
    std::reverse(redirected_balanced_ternary.begin(),
                 redirected_balanced_ternary.end());

    for (int i = 0; i < int(redirected_balanced_ternary.size()); ++i) {
        if (redirected_balanced_ternary[i] == 1) {
            symbols[i] = (invert_signs) ? '-' : '+';
        } else if (redirected_balanced_ternary[i] == -1) {
            symbols[i] = (invert_signs) ? '+' : '-';
        }
    }

    return symbols;
}

std::unordered_map<int, std::vector<int>> value_to_values;

}  // namespace

std::string balanced_convert(int value) {
    bool invert_signs = false;

    if (value < 0) {
        invert_signs = true;
        value = abs(value);
    }

    if (!value_to_values.count(value)) {
        value_to_values[value] = initalize_values(value);
    }

    auto ternary = make_ternary(value_to_values.find(value)->second, value);

    convert_to_balanced(ternary);
    auto symbols = convert_to_symbols(ternary, invert_signs);

    return symbols;
}

}  // namespace ternary
