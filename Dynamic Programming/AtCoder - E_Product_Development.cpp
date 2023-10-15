#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

ll dp[6][6][6][6][6];

inline void umin(ll& a, ll b) {
    if (a > b) a = b;
}

int main() {
    int N, K, P;
    cin >> N >> K >> P;
    int MX = 6;
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            for (int k = 0; k < MX; k++) {
                for (int m = 0; m < MX; m++) {
                    for (int n = 0; n < MX; n++) {
                        dp[i][j][k][m][n] = 1e18;
                    }
                }
            }
        }
    }
    vector<vector<int>> A(N, vector<int>(K));
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }
    dp[0][0][0][0][0] = 0;
    for (int u = 0; u < N; u++) {
        for (int i = MX - 1; i >= 0; i--) {
            for (int j = MX - 1; j >= 0; j--) {
                for (int k = MX - 1; k >= 0; k--) {
                    for (int m = MX - 1; m >= 0; m--) {
                        for (int n = MX - 1; n >= 0; n--) {
                            if (dp[i][j][k][m][n] == 1e18) { continue; }
                            int mask[] = { i, j, k, m, n };
                            int dest[] = { 0, 0, 0, 0, 0 };
                            for (int t = 0; t < K; t++) {
                                dest[t] = min(mask[t]+A[u][t], P);
                            }
                            umin(dp[dest[0]][dest[1]][dest[2]][dest[3]][dest[4]], dp[i][j][k][m][n] + C[u]);
                        }
                    }
                }
            }
        }
    }
    int dest[] = { 0, 0, 0, 0, 0 };
    for (int t = 0; t < K; t++) {
        dest[t] = P;
    }
    ll ans = dp[dest[0]][dest[1]][dest[2]][dest[3]][dest[4]];
    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}