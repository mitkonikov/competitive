#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll L, R;
    cin >> L >> R;
    ll D = R - L;
    ll ans = (-1 + sqrt(1 + 8 * D)) / 2 + 1;
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