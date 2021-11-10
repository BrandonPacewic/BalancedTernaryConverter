#include <bits/stdc++.h>

using namespace std;


int main() {
    int x;
    cin >> x;

    vector<int> values;
    for (int i = 0; pow(3, i) <= x; i++) 
        values.push_back(pow(3, i));

    vector<int> ternary(values.size(), 0);
    for (int i = values.size() - 1; i >= 0; i--) {
        for (int k = 0; k < 2; k++)
            if (x >= values[i]) {
                x -= values[i];
                ternary[i] += 1;
            }
    }

    for (int i = ternary.size() - 1; i >= 0; i--)
        cout << ternary[i];
}