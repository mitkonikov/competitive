#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll powers[30];

vector<vector<bool>> gen(21);

void testCase() {
    ll g, p;
    cin >> g >> p;
    p--;
    p %= gen[g].size();
    cout << (gen[g][p] ? "MANGO" : "APPLE") << endl;
}

int main() {
    gen[1].push_back(1);
    for (int i = 1; i <= 19; i++) {
        for (int j = 0; j < gen[i].size(); j++) {
            gen[i+1].push_back(gen[i][j]);
            gen[i+1].push_back(gen[i][j] ^ 1);
        }
    }

    powers[0] = 1;
    for (int i = 1; i < 30; i++) {
        powers[i] = powers[i-1] * 2;
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}