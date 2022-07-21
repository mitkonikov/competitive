#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    ll K;
    cin >> n >> K;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<ll, int> frq;
    frq[0] = 1;
    
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + v[i];
        ans = ans + frq[sum - K];
        frq[sum]++;
    }

    cout << ans << endl;
    return 0;
}