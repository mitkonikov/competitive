#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll a, b;
    cin >> a >> b;
    // b - 2 * x >= y
    // y + x = a
    ll L = 0, R = a + 1;
    while (R - L > 1) {
        ll MID = (L + R) / 2;
        ll left = a - MID;
        if (MID >= b - (ll)2 * left) {
            L = MID;
        } else {
            R = MID;
        }
    }
    cout << L << endl;
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