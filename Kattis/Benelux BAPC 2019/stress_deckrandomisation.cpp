#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int> &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != i+1) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> alice(n), bob(n);
    for (int i = 0; i < n; i++) cin >> alice[i];
    for (int i = 0; i < n; i++) cin >> bob[i];

    vector<int> s(alice);
    
    int count = 1;
    bool turn = false;
    while (!check(s)) {
        for (auto ss: s) cout << ss << " ";
        cout << endl;
        vector<int> tmp(n);

        if (turn) { // alice
            for (int i = 0; i < n; i++) {
                tmp[i] = s[alice[i]-1];
            }

            copy(tmp.begin(), tmp.end(), s.begin());
        } else { // bob
            for (int i = 0; i < n; i++) {
                tmp[i] = s[bob[i]-1];
            }

            copy(tmp.begin(), tmp.end(), s.begin());
        }

        turn = !turn;
        count++;
    }

    cout << count << endl;

    return 0;
}