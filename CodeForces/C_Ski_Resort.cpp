#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll cons = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] <= Q) {
            cons++;
        } else {
            if (cons >= K) {
                // how many subarrays of length K or bigger are there in a range "cons"
                //  (cons - K + 1) of length K
                //  (cons - (K+1) + 1) of length K+1
                //  (.... - (K+2)) of length cons
                ans += (ll)(cons - K + 1) * (cons + 1 - K) - ((cons-K) + 1) * (cons-K) / 2;
            }
            cons = 0;
        }
    }
    if (cons >= K) ans += (ll)(cons - K + 1) * (cons + 1 - K) - ((cons-K) + 1) * (cons-K) / 2;
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