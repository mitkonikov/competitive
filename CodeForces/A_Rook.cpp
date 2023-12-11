#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    for (int i = 1; i <= 8; i++) {
        string nS = S;
        nS[1] = '0' + i;
        if (nS != S) cout << nS << endl;
    }
    for (int i = 0; i <= 7; i++) {
        string nS = S;
        nS[0] = 'a' + i;
        if (nS != S) cout << nS << endl;
    }
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