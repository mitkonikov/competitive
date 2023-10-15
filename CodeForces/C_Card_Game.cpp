#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline void umax(ll& a, ll b) {
    if (b > a) a = b;
}

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    dp[N-1][0] = 0;
    umax(dp[N-1][1], A[N-1]);
    for (int i = N-2; i >= 0; i--) {
        umax(dp[i][0], dp[i+1][0]);
        umax(dp[i][0], dp[i+1][1]);
        umax(dp[i][1], dp[i+1][0]);
        umax(dp[i][1], dp[i+1][0] + A[i]);
        umax(dp[i][1], dp[i+1][1] + A[i]);
    }

    cout << dp[0][1] << endl;
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