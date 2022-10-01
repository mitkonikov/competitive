#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    ll ans = LLONG_MAX;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        ll right = 0;
        for (int j = i - 1; j >= 0; j--) {
            ll times = (right / v[j]) + 1;
            cur += times;
            right = times * v[j];
        }
        
        right = 0;
        for (int j = i + 1; j < n; j++) {
            ll times = (right / v[j]) + 1;
            cur += times;
            right = times * v[j];
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;
    return 0;
}