#include <bits/stdc++.h>
#define ll long long

using namespace std;

// [start,end)
ll binary_search(function<bool(ll)> func, ll start, ll end) {
    /* func:int ->bool
        returns smallest int x where func(x) evaluates to true, searches in [start,end), it is assumed the values are false, .. , false, true ...
    */

    if (end <= start) return end;   // has to be here, otherwise func(end-1) in next line could be a problem
    if (!func(end-1)) return end;
    while (end - start > 1) {
        ll mid = (start + end) / 2;
        if (func(mid)) end = mid; else start = mid;
    }

    return (func(start) ? start : end);
};

void testCase() {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a.push_back((ll)2e18);
    n++;

    ll k = binary_search([&](ll K) {
        ll damage = h;
        for (int i = 1; i < n; i++) {
            damage = damage - min(K, a[i] - a[i-1]);
            if (damage <= 0) break;
        }

        return (damage <= 0);
    }, 0LL, h * 2);
    
    ll damage = h;
    for (int i = 1; i < n; i++) {
        damage = damage - min(k-1, a[i] - a[i-1]);
        if (damage <= 0) break;
    }

    if (damage <= 0) {
        cout << k - 1 << endl;
    } else {
        cout << k << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}