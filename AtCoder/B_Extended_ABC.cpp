#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    char expect = 'A';
    bool ok = true;
    for (int i = 0; i < S.size(); i++) {
        ok &= (S[i] >= expect);
        expect = max(expect, S[i]);
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}