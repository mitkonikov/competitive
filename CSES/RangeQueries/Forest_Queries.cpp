#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int M = N;
    vector<vector<int>> mat(N, vector<int>(M, 0));
    vector<vector<int>> dp(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == '*') mat[i][j]++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = mat[i][j];
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
            if (i && j) dp[i][j] -= dp[i-1][j-1];
        }
    }
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        int ans = dp[x2][y2];
        if (x1) ans -= dp[x1-1][y2];
        if (y1) ans -= dp[x2][y1-1];
        if (x1 && y1) ans += dp[x1-1][y1-1];
        cout << ans << endl;
    }
    return 0;
}