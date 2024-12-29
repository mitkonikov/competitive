#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    ll L = -1, R = N + 1;
    while (R - L > 1) {
        ll M = (R + L) / 2;
        ll F = M / 3;
        ll K = F * (A + B + C);
        if (M % 3 == 1) K += A;
        if (M % 3 == 2) K += A + B;
        if (K >= N) {
            R = M;
        } else {
            L = M;
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