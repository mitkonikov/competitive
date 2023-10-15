#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    bool ok = 1;
    for (int i = 1; i < S.size(); i += 2) {
        ok &= (S[i] == '0');
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}