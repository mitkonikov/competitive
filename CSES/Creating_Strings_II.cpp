#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
            e--;
            continue;
        }

        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

int main() {
    const int MX = 1e6 + 1e4;
    const int MOD = 1e9 + 7;
    vector<ll> fact(MX, 1);    
    for (int i = 1; i < MX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    string S;
    cin >> S;
    vector<int> frq(26);
    int N = S.size();
    for (int i = 0; i < N; i++) {
        frq[S[i] - 'a']++;
    }

    ll ans = fact[N];
    for (int i = 0; i < 26; i++) {
        if (frq[i]) ans = (ans * expo(fact[frq[i]], MOD - 2, MOD)) % MOD;
    }

    cout << ans << endl;
    return 0;
}