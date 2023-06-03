#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    string ans = "";
    for (int i = 0; i < min((int)S.size(), 3); i++) {
        ans += S[i];
    }
    while (ans.size() < S.size()) ans += "0";
    cout << ans << endl;
    cout << flush;
    return 0;
}