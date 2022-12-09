#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;
const int mxn = 110;
int dp[mxn][mxn][mxn][mxn];

inline void uadd(int& a, int b) {
    a = (a + b);
    if (a >= MOD) a -= MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // dp[i][j][t][k] - I'm on the i-th index,
    //                  I have chosen j elements till now
    //                  My target is t
    //                  with a sum of k;

    for (int t = 1; t <= n; t++) {
        dp[0][0][t][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 1; t <= n; t++) {
                for (int k = 0; k < n; k++) {
                    uadd(dp[i][j+1][t][(k+v[i])%t], dp[i-1][j][t][k]);
                    uadd(dp[i][j][t][k], dp[i-1][j][t][k]);
                }
            }
        }
    }

    int ans = 0;
    for (int t = 1; t <= n; t++) {
        uadd(ans, dp[n][t][t][0]);
    }

    cout << ans << endl;
    return 0;
}