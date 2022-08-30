#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    vector<int> inc(n-1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        inc[x] += y;
    }
    bool ok = true;
    for (int i = 0; i < n-1; i++) {
        if (t - a[i] + inc[i] <= 0) {
            ok = false;
            break;
        }

        t = t - a[i] + inc[i];
    }
    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}