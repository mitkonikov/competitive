#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    string ans = "";
    bool ok = 1;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '|') {
            ok ^= 1;
        }

        if (ok && S[i] != '|') {
            ans += S[i];
        }
    }
    cout << ans << endl;
    return 0;
}