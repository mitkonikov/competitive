#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> frq(3e5 + 1000);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        frq[v[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= mx; i++) {
        for (int j = 1; j <= mx / i; j++) {
            ans = ans + ((ll)frq[i] * frq[j] * frq[i * j]);
        }
    }

    cout << ans << endl;
    return 0;
}