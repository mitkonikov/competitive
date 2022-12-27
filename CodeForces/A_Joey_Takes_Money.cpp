#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    ll product = 1;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        product *= x;
    }
    ll ans = product + (n - 1);
    cout << ans * 2022 << endl;
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