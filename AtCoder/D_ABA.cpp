#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> pref(N, vector<int>(26, 0)), suff(N, vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        if (i) pref[i] = pref[i-1];
        pref[i][S[i]-'A']++;
    }
    for (int i = N - 1; i >= 0; i--) {
        if (i < N - 1) suff[i] = suff[i+1];
        suff[i][S[i]-'A']++;
    }
    ll ans = 0;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j < 26; j++) {
            ans += (ll)pref[i-1][j] * suff[i+1][j];
        }
    }
    cout << ans << endl;
    return 0;
}