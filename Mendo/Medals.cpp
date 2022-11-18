// Task: https://mendo.mk/Task.do?id=55

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][a[0]-1] = 1;
    for (int i = 1; i < n; i++) {
        int m = a[i] - 1;
        for (int j = 0; j < 3; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
        for (int j = 0; j <= m; j++) {
            dp[i][m] = max(dp[i][m], dp[i-1][j] + 1);
        }
    }
    return n - *max_element(dp.back().begin(), dp.back().end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];   
    int ans = solve(a);
    reverse(a.begin(), a.end());
    ans = min(ans, solve(a));
    cout << ans << endl;
    return 0;
}