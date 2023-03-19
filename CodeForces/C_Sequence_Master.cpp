#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N;
    cin >> N;
    N *= 2;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    if (N == 2) {
        cout << abs(A[0] - A[1]) << endl;
        return;
    }
    ll ans = LLONG_MAX;
    if (N == 4) {
        for (int check: { 0, 2 }) {
            ll s = 0;
            for (int j = 0; j < N; j++) {
                s += abs(check - A[j]);
            }
            ans = min(ans, s);
        }
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(A[i]);
    }
    ans = min(ans, sum);
    if ((N/2) % 2 == 0) {
        ll sum1 = 0;
        for (int i = 0; i < N; i++) {
            sum1 += abs(-1 - A[i]);
        }
        for (int i = 0; i < N; i++) {
            ans = min(ans, sum1 - abs(-1-A[i]) + abs(N/2-A[i]));
        }
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