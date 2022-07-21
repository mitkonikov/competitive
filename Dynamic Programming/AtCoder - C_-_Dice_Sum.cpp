#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MOD = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int dp[60][2510];
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 2510; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= M; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            for (int m = 1; m <= M; m++) {
                if (k-m >= 0) dp[i][k] = ((ll)dp[i][k] + dp[i-1][k-m]) % MOD;
            }
        }
    }

    ll sum = 0;
    for (int k = 0; k <= K; k++) {
        sum = (sum + dp[N-1][k]) % MOD;
    } cout << sum << endl;

    return 0;
}