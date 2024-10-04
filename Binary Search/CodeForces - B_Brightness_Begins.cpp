#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll K;
    cin >> K;
    ll L = 0, R = 2e18;
    while (R - L > 1) {
        ll MID = (R - L) / 2 + L;
        ll num = MID - floor(sqrt(MID));
        if (num < K) {
            L = MID;
        } else {
            R = MID;
        }
    }
    cout << R << endl;
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