#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class BALANCED_TERNARY_CONVERTER {
private: 
    template<typename T> 
    T abs(T T_Type) { 
        return T_Type < 0 ? T_Type *= -1 : T_Type; 
    }

    template<typename T_Num>
    std::vector<int64_t> initalizeValues(const T_Num ValueToBeConverted) {
        std::vector<int64_t> VALUES;

        for (int i = 0; pow(3, i) <= abs(ValueToBeConverted); i++) {
            VALUES.push_back(int64_t(pow(3, i)));
        }

        sort(VALUES.begin(), VALUES.end(), std::greater<int64_t>());
        
        return VALUES;
    }

    std::vector<int> makeTernaryArray(const std::vector<int64_t> VALUES, int64_t valueToBeConverted) {
        std::vector<int> ternaryArray(VALUES.size(), 0);

        for (int i = 0; i < VALUES.size(); i++) { 
            for (int j = 0; j < 2; j++) { 
                if (abs(valueToBeConverted) >= VALUES[i]) {
                    ternaryArray[i]++;
                    valueToBeConverted = abs(valueToBeConverted) - VALUES[i]; 
                }
            }
        }

        return ternaryArray;
    }

    void convertTernaryArrayToBalancedTernary(std::vector<int> &ternaryArray) {
        for (int i = ternaryArray.size() - 1; i > 0; i--) {
            if (ternaryArray[i] == 3) {
                ternaryArray[i] = 0;
                ternaryArray[i-1]++;
            } else if (ternaryArray[i] == 2) {
                    ternaryArray[i-1]++; 
                    ternaryArray[i] = -1;
            } 
        }
    }

    std::vector<char> convertToSymbols(const std::vector<int> &balancedTernaryArray, const bool invertSigns = false) {
        std::vector<char> ans(balancedTernaryArray.size(), '0');
        
        for (int i = 0; i < balancedTernaryArray.size(); i++) {
            if (balancedTernaryArray[i] == 1) {
                ans[i] = invertSigns ? '-' : '+';
            } else if (balancedTernaryArray[i] == -1) 
                ans[i] = invertSigns ? '+' : '-';
        }

        return ans;
    }

    void printAnswer(const std::vector<char> &ans) {
        for (auto i : ans) {
            std::cout << i;
        }
        std::cout << std::endl;
    }

public: 
    template<typename T_Num>
    void convert(T_Num valueToBeConverted) {
        int64_t standardizedValueToBeConverted = int64_t(valueToBeConverted);
        bool invertSigns = false;

        if (standardizedValueToBeConverted < 0) {
            invertSigns = true;
        }

        std::vector<int64_t> values = initalizeValues(standardizedValueToBeConverted);
        
        std::vector<int> ternaryArray = makeTernaryArray(values, standardizedValueToBeConverted);

        convertTernaryArrayToBalancedTernary(ternaryArray);

        std::vector<char> ans = convertToSymbols(ternaryArray, invertSigns);

        printAnswer(ans);
    }
};