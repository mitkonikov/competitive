// 
//   Let N be a positive integer. You are given a string s of length N−1, consisting of < and >.
//   Find the number of permutations (p[1], p[2], ... p[N]) of (1,2, ... N) 
//   that satisfy the following condition, modulo 10^9 + 7 
//   For each i (1 <= i <= N−1), p[i] < p[i+1] if the i-th character in s is '<' 
//                           and p[i] > p[i+1] if the i-th character in s is '>'
// 
//      Time Complexity: O(N^2)
// 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

inline void uadd(int& a, int b) {
    a = (a + b);
    if (a >= MOD) a -= MOD;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    // dp[i][j] - number of ways to order the first i elements ending with item j
    for (int i = 1; i < n; i++) {
        int pref = 0;
        for (int j = 0; j <= i; j++) { // last number
            if (s[i] == '<') {
                uadd(dp[i][j], pref);
                uadd(pref, dp[i-1][j]);
            } else {
                uadd(dp[i][i-j], pref);
                uadd(pref, dp[i-1][i-j-1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        uadd(ans, dp[n-1][i]);
    }

    cout << ans << endl;
    return 0;
}