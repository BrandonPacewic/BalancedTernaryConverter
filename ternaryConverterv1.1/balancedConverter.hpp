template <typename T> T balancedConverter(T conVal) {
    int64_t inVal = conVal;
    vector<int64_t> vals;
    for (int i = 0; pow(3, i) <= conVal; i++) {
        vals.push_back(int64_t(pow(3, i)));
        cout << "added " << pow(3, i) << '\n';
    }

    sort(vals.begin(), vals.end(), greater<int64_t>());

    vector<int> balTer(vals.size(), 0);
    for (int i = 0; i < vals.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (inVal >= vals[i]) {
                balTer[i]++;
                inVal -= vals[i]; 
                cout << "removed " << vals[i] << '\n';
            }
        }

        // if (balTer[i] == 3) {
        //     balTer[i] = 0;
        // } else if (balTer[i] == 2) {
        //     balTer[i] = -1;
        //     balTer[i-1]++;
        // }
    }

    for (auto i: balTer)
        cout << i << ' ';
    return conVal;
}