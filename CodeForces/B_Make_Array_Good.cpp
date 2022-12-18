#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<ll, ll>> ops;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        ll target = 0;
        ll L = 1, R = 1e9;
        while (R - L > 1) {
            ll MID = L + (R - L) / 2;
            if (MID * a[i-1].first < a[i].first) {
                L = MID;
            } else {
                R = MID;
            }
        }
        for (ll off = L - 1; off <= L + 4; off++) {
            if (off * a[i-1].first >= a[i].first) {
                ll diff = off * a[i-1].first - a[i].first;
                ops.push_back({ a[i].second, diff });
                a[i].first += diff;
                break;
            }
        }
    }
    cout << ops.size() << endl;
    for (auto el: ops) {
        cout << el.first + 1 << " " << el.second << endl;
    }
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