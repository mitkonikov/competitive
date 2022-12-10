#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[110][110][110];

inline void umax(ll& a, ll b) {
    a = max(a, b);
}

int main() {
    memset(dp, -1, sizeof dp);
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int t = 0; t <= K; t++) {
            for (int d = 0; d < D; d++) {
                if (t == 0 && d == 0) umax(dp[i+1][t+1][(d+a[i])%D], a[i]);
                if (dp[i][t][d] != -1) umax(dp[i+1][t+1][(d+a[i])%D], dp[i][t][d] + a[i]);
                umax(dp[i+1][t][d], dp[i][t][d]);
            }
        }
    }
    ll ans = dp[N][K][0];
    cout << ans << endl;
    return 0;
}