#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> frq(26);
    for (int i = 0; i < S.size(); i++) frq[S[i] - 'a']++;
    vector<int> app(110);
    for (int i = 0; i < 26; i++) app[frq[i]]++;
    bool ok = true;
    for (int i = 1; i < app.size(); i++) ok &= (app[i] == 0 || app[i] == 2);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}