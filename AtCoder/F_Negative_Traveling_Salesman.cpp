#include <bits/stdc++.h>
#define ll long long

using namespace std;

void umin(int& a, int b) {
    if (b < a) a = b;
}

int main() {
    int N, M;
    cin >> N >> M;
    const int INF = 1e9;
    vector<vector<int>> mat(N, vector<int>(N, INF));
    vector<vector<bool>> b_mat(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        mat[u][v] = w;
        b_mat[u][v] = true;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                umin(mat[i][j], mat[i][k] + mat[k][j]);
                if (b_mat[i][k] && b_mat[k][j]) b_mat[i][j] = true;
            }
        }
    }
    vector<vector<int>> dp(N, vector<int>((1 << N), INF));
    vector<vector<bool>> bdp(N, vector<bool>((1 << N), false));
    for (int i = 0; i < N; i++) {
        dp[i][(1 << i)] = 0;
        bdp[i][(1 << i)] = true;
    }
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int last = 0; last < N; last++) {
            for (int next = 0; next < N; next++) {
                umin(dp[next][mask | (1 << next)], dp[last][mask] + mat[last][next]);
                if (bdp[last][mask] && b_mat[last][next]) bdp[next][mask | (1 << next)] = true;
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++) {
        if (bdp[i][(1 << N) - 1]) {
            ans = min(ans, dp[i][(1 << N) - 1]);
        }
    }
    if (ans == INF) cout << "No" << endl;
    else cout << ans << endl;
    return 0;
}