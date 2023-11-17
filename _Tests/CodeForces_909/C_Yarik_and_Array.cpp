#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    const ll INF = -1e18;
    vector<vector<ll>> dp(2, vector<ll>(N, INF));
    ll ans = INF;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            dp[1][i] = max(A[i], (i?dp[0][i-1]:INF) + A[i]);
        } else {
            dp[0][i] = max(A[i], (i?dp[1][i-1]:INF) + A[i]);
        }

        ans = max({ ans, dp[0][i], dp[1][i] });
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