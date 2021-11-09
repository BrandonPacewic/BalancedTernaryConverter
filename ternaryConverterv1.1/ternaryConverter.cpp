#include <bits/stdc++.h>

using namespace std;


//fix things please think about last night

int main() {
    int x;
    cin >> x;

    vector<int> values;
    for (int i = 0; pow(3, i) <= x; i++) {
        values.push_back(pow(3, i));
        cout << "worked " << pow(3, i) << '\n';
    }

    vector<int> ternery(values.size(), 0);
    for (int i = values.size() - 1; i >= 0; i--){
        for (int k = 0; k < 2; k++)
            if (x >= values[i]) {
                x -= values[i];
                ternery[i] += 1;
            }
    }

    for (auto i: ternery)
        cout << i;
}