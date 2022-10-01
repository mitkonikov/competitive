#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n+1), c(m+1);
    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i <= m; i++) cin >> c[i];
    
    vector<ll> b(n+1);
    for(int i = 2; i <= n; i++) b[i] = v[i-1] - b[i-1];
    
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ll r = c[j] - b[i];
            if (i % 2 == 0) r *= -1;
            mp[r]++;
        }
    }
    
    ll ans = 0;
    for(auto p : mp) ans = max(ans, p.second);
    cout << ans << endl;
    return 0;
}