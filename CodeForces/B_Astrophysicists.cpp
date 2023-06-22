#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, K, G;
    cin >> N >> K >> G;
    // R < G / 2 => 2 * R < G
    ll each = (G + 1) / 2 - 1;
    ll ans = 0;
    if (N * each <= K * G) {
        ans = N * each;
        ll left = K * G - N * each;
        left %= G;
        if (left > 0) {
            ans -= each;
            ans -= (G - (each + left));
        }
    } else {
        ans = K * G;
    }
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