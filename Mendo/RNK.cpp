#include <bits/stdc++.h>

using namespace std;

inline bool match(char a, char b) {
    if (a == 'A' && b == 'U') return true;
    if (a == 'U' && b == 'A') return true;
    if (a == 'C' && b == 'G') return true;
    if (a == 'G' && b == 'C') return true;
    if (a == 'G' && b == 'U') return true;
    if (a == 'U' && b == 'G') return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n));

    for (int size = 2; size < n; size++) {
        for (int pos = 0; pos < n - size; pos++) {
            int L = pos;
            int R = pos + size;

            for (int i = L + 2; i <= R; i++) {
                dp[L][R] = max({ 
                    dp[L][R], 
                    match(s[L], s[i]) 
                       + (L+1 <= i-1 ? dp[L+1][i-1] : 0) 
                       + (i+1 <= R ? dp[i+1][R]: 0),
                    dp[L+1][R]
                });
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}