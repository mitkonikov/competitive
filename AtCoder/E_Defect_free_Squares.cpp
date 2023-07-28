#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<bool>> A(H, vector<bool>(W, 1));
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u][v] = 0;
    }
    vector<vector<int>> dp(H, vector<int>(W, 0));
    ll ans = 0;
    for (int i = 0; i < H; i++) ans += (dp[i][0] = A[i][0]);
    for (int j = 1; j < W; j++) ans += (dp[0][j] = A[0][j]);
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            if (A[i][j]) {
                dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1;
            } else {
                dp[i][j] = 0;
            }
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}