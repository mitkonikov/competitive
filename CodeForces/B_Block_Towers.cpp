#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    ll t1;
    cin >> t1;
    vector<ll> a(n-1);
    for (int i = 0; i < n-1; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        ll take = (a[i] - t1) / 2;
        t1 += max(0LL, take);
        a[i] -= take;
        if (a[i] > t1) {
            a[i]--;
            t1++;
        }
    }
    cout << t1 << endl;
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