#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;
    vector<ll> START(n + 10, INT_MAX);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        START[a] = min(START[a], (ll)b);
    }
    ll suff = n;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        suff = min(suff, START[i]);
        ans += max(0LL, (suff - i));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}