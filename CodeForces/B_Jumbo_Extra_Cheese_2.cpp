#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y < x) swap(x, y);
        a[i] = { y, x };
        ans += 2LL * x;
    }

    sort(a.begin(), a.end());
    cout << ans + (2LL * a.back().first) << endl;
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