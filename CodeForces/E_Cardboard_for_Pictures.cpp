#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    ll C;
    cin >> C;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // sum of (A[i] + 2w)^2 = c
    // sum of A[i]^2 + 2 * A[i] * 2w + 4w^2
    ll L = 0, R = 1e9 + 10;
    while (R - L > 1) {
        ll M = (R + L) / 2;
        ll sum = 0;
        bool fail = false;
        for (int i = 0; i < N; i++) {
            ll c = (A[i] + 2LL * M) * (A[i] + 2LL * M);
            if (c > C || sum + c > C) {
                fail = true;
                R = M;
                break;
            }
            sum += c;
        }

        if (fail) continue;

        if (sum > C) {
            R = M;
        } else {
            L = M;
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