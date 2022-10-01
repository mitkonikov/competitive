#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define ll long long
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

ll solve(vector<int> a, int MAX) {
    int n = a.size();
    ll twos = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        int diff = MAX - a[i];
        twos = twos + (ll)diff / 2;
        ones = ones + (ll)diff % 2;
    }

    ll ans = binary_search([&](ll days) {
        ll T = 0, O = 0;
        if (days % 2 == 0) {
            O = days / 2;
            T = days / 2;
        } else {
            O = days / 2 + 1;
            T = days / 2;
        }

        if (T * 2 + O < twos * 2 + ones) return false;
        if (O < ones) return false;
        ll taken_twos = min(T, twos);
        ll taken_ones = min(O, ones);

        ll rem_twos = twos - taken_twos;
        ll rem_ones = O - taken_ones;
        if (rem_ones >= rem_twos * 2) return true;
        return false;
    }, 0, twos * 2 + ones * 2 + 1);
    return ans;
}

void testCase() {
    int n;
    cin >> n;

    vector<int> a(n);
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        MAX = max(MAX, a[i]);
    }

    cout << min(solve(a, MAX), solve(a, MAX + 1)) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}