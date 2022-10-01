#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    vector<int> which(n);
    for (int i = 0; i < n; i++) {
        cin >> which[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (which[i]) a.push_back(x);
        else b.push_back(x);
    }
    if (a.size() == 0 || b.size() == 0) {
        ll ans = 0;
        for (int i = 0; i < a.size(); i++) ans += a[i];
        for (int i = 0; i < b.size(); i++) ans += b[i];
        cout << ans << endl;
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (b.back() > a.back()) b.swap(a);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int mn = min(a.size(), b.size());
    ll ans = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
    for (int i = 0; i < mn; i++) {
        ans += (a[i] + b[i]);
    }
    if(2 * mn == n) ans -= min(a[mn-1], b[mn-1]);
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