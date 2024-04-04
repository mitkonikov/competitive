#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    bool ok = true;
    for (int i = 0; i < S.size(); i++) {
        if (i == 0) ok &= (S[i] >= 'A' && S[i] <= 'Z');
        else ok &= (S[i] >= 'a' && S[i] <= 'z');
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}