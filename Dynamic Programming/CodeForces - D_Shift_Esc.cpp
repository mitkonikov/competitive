#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void update(ll& a, ll b) {
    if (b < a) a = b;
}

void testCase() {
    int N, M;
    cin >> N >> M;
    ll K;
    cin >> K;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(M, vector<ll>(M, 1e18 + 10)));
    for (int i = 0; i < M; i++) {
        dp[0][0][i] = A[0][i] + K * i;
    }
    for (int i = 1; i < M; i++) {
        for (int shift = 0; shift < M; shift++) {
            update(dp[0][i][shift], dp[0][i-1][shift] + A[0][(i + shift) % M]);
        }
    }
    for (int i = 0; i < M; i++) {
        for (int shift = 0; shift < M; shift++) {
            update(dp[0][i][0], dp[0][i][shift]);
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int shift = 0; shift < M; shift++) {
                if (j) update(dp[i][j][shift], dp[i][j-1][shift] + A[i][(j + shift) % M]);
                update(dp[i][j][shift], dp[i-1][j][0] + A[i][(j + shift) % M] + (K * shift));
            }
        }
        for (int j = 0; j < M; j++) {
            for (int shift = 0; shift < M; shift++) {
                update(dp[i][j][0], dp[i][j][shift]);
            }
        }
    }
    cout << dp[N-1][M-1][0] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}