void ternaryCon(int input) {
    int n = 0;
    if (input < 0)
        n++;

    vector<int> values;
    for (int i = 0; pow(3, i) <= input; i++) 
        values.push_back(pow(3, i));

    vector<int> ternary(values.size(), 0);
    for (int i = values.size() - 1; i >= 0; i--) {
        for (int k = 0; k < 2; k++)
            if (input >= values[i]) {
                input -= values[i];
                ternary[i] += 1;
            }
    }
    
    for (auto i: ternary)
        cout << i << ' ';
}