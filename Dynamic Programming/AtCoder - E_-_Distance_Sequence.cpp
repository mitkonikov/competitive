#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    ll MOD = 998244353;
    vector<vector<int>> dp(n, vector<int>(m + 10, 0));
    for (int i = 0; i < m; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        ll sum = 0;
        ll allSum = 0;
        for (int j = 0; j < m; j++) {
            allSum = (allSum + dp[i-1][j]) % MOD;
        }

        for (int j = 0; j < k; j++) {
            sum = (sum + dp[i-1][j]) % MOD;
        }
        dp[i][0] = (allSum - sum + MOD) % MOD;
        
        for (int j = 1; j < m; j++) {
            // j - k .... j + k
            // rolling sums
            sum = (sum - (j-k>=0 ? dp[i-1][j-k] : 0) + MOD) % MOD;
            sum = (sum + (j+k-1<m ? dp[i-1][j+k-1] : 0)) % MOD;
            dp[i][j] = (allSum - sum + MOD) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}