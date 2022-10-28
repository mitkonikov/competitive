#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void uadd(int& a, int b) {
    a += b;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    if (n == 1) {
        if (mat[0][0] == 0) {
            cout << 1 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    
    vector<vector<map<int, int>>> dp(n, vector<map<int, int>>(n));
    vector<vector<map<int, int>>> dp1(n, vector<map<int, int>>(n));
    dp[0][0][mat[0][0]] = 1;
    dp1[n-1][n-1][mat[n-1][n-1]] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            for (auto el: dp[i][j]) {
                if (i + 1 < n) {
                    uadd(dp[i+1][j][el.first ^ mat[i+1][j]], el.second);
                }
                if (j + 1 < n) {
                    uadd(dp[i][j+1][el.first ^ mat[i][j+1]], el.second);
                }
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= (n-1-i); j--) {
            for (auto el: dp1[i][j]) {
                if (i - 1 >= 0) {
                    uadd(dp1[i-1][j][el.first ^ mat[i-1][j]], el.second);
                }
                if (j - 1 >= 0) {
                    uadd(dp1[i][j-1][el.first ^ mat[i][j-1]], el.second);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = (n - 1 - i);
        for (auto el: dp[i][j]) {
            ans += (ll)el.second * dp1[i][j][el.first ^ mat[i][j]];
        }
    }
    cout << ans << endl;
    return 0;
}