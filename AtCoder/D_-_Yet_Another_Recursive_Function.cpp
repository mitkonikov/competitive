#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

unordered_map<ll, ll> dp;

ll calc(ll n) {
    if (n == 0) return 1;
    auto it = dp.find(n);
    if (it != dp.end()) {
        return it->second;
    }

    return dp[n] = calc(n / 2) + calc(n / 3);
}

int main() {
    ll n;
    cin >> n;
    cout << calc(n) << endl;
    cout << flush;
    return 0;
}