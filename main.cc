#include "ternaryConverterv1.1/balancedTernaryConverter.hpp"
#include <iostream>
using namespace std;

int main() {
    BALANCED_TERNARY_CONVERTER balancedTernaryConverter;
    long long input;
    cin >> input;

    balancedTernaryConverter.convert(input);
}