#include <bits/stdc++.h>

using namespace std;


//fix things please think about last night

int main() {
    int x;
    cin >> x;
    // cout << pow(0, 3) << '\n';
    // cout << 5 > x * float(2)/float(3) << '\n';

    vector<int> values;
    int size = 0;
    for (int i = 0; pow(3, i) < ((x * float(2)/float(3)) + 1); i++) {
        values.push_back(pow(3, i));
        cout << "worked " << pow(3, i) << '\n';
        size++;
    }

    if (values[size - 1] < (x * float(2)/float(3))) {
        values.push_back(pow(3, size));
        cout << "worked " << pow(3, size) << '\n';
        size++;
    }

    vector<int> ternery(size, 0);
    for (int i = size - 1; i >= 0; i--){
        for (int k = 0; k < 2; k++)
            if (x >= values[i]) {
                x -= values[i];
                ternery[i] += 1;
            }
    }

    for (auto i: ternery)
        cout << i;
}