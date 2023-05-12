#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    bool same = 1;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != S[0]) same = 0;
    }
    if (same) {
        cout << -1 << endl;
        return;
    }
    cout << S.size() - 1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}