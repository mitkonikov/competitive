#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    ll L = 0, R = 1e18 / k;
    while (R - L > 1) {
        ll MID = (L + R) / 2;
        ll sum = 0;
        for (auto element: v) sum = sum + min(MID, (ll)element);
        if (sum >= k * MID) L = MID;
        else R = MID;
    }

    cout << L << endl;
    return 0;
}