#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll left = k;
    for (int i = 0; i < n; i++) {
        ll num = a[i] / x;
        a[i] -= min(left, num) * x;
        left -= min(left, num);
        if (left == 0) break;
    }

    if (left != 0) {
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < min((int)left, (int)a.size()); i++) {
            a[i] = 0;
        }
    }

    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
    return 0;
}