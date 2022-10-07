// 
//   You are given strings s and t. 
//   Find one longest string that is a subsequence (non-continuous) of both s and t.
// 
//   Time Complexity: O(NM)
// 

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = (int)s.size(), m = (int)t.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = (s[0] == t[0]);
    for (int i = 1; i < n; i++) dp[i][0] = max(dp[i-1][0], (int)(s[i] == t[0]));
    for (int i = 1; i < m; i++) dp[0][i] = max(dp[0][i-1], (int)(s[0] == t[i]));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max({
                dp[i-1][j-1] + (s[i] == t[j]),
                dp[i-1][j],
                dp[i][j-1]
            });
        }
    }

    // this is the length of the LCS
    // cout << dp[n-1][m-1] << endl;

    if (dp[n-1][m-1] == 0) {
        cout << "" << endl;
        return 0;
    }

    int i = n-1;
    int j = m-1;

    string ans = "";
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            ans += s[i];
            i--; j--;
            continue;
        }

        if (i == 0) j--;
        else if (j == 0) i--;
        else {
            if (dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}