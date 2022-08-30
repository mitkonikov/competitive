#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int mxf = 92, mxp = 90;
ll fib[mxf];
ll pref_fib[mxp];

void testCase() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int mx = 0;
    while (mx < mxp && sum > pref_fib[mx]) mx++;

    if (sum != pref_fib[mx]) {
        cout << "NO" << endl;
        return;
    }

    priority_queue<ll, vector<ll>, less<ll>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    bool ok = true;
    vector<bool> visited(mx+1, false);

    ll reserve = -1;
    for (int i = mx; i >= 0; i--) {
        if (pq.empty()) {
            ok = false;
            break;
        }

        auto top = pq.top(); pq.pop();
        if (top < fib[i]) {
            ok = false;
            break;
        }
        top -= fib[i];
        visited[i] = true;
        if (reserve > 0) pq.push(reserve);
        reserve = top;
    }

    ok &= (reserve <= 0);
    
    int mx_taken = 0;
    for (int i = 0; i <= mx; i++) {
        if (visited[i]) mx_taken = i;
    }

    for (int i = 0; i <= mx_taken && ok; i++) {
        if (!visited[i]) ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < mxf; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    pref_fib[0] = 1;
    for (int i = 1; i < mxp; i++) {
        pref_fib[i] = pref_fib[i-1] + fib[i];
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}