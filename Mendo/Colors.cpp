// Task: https://mendo.mk/Task.do?id=128

#include <bits/stdc++.h>

using namespace std;

int solve(const vector<vector<int>> &happy, int n, int first_color) {
    vector<vector<int>> dp(n, vector<int>(3, 1e9));

    for (int k = 0; k < 3; k++) {
        dp[0][k] = happy[0][first_color];
    }

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            int ans = 1e9;

            for (int l = 0; l < 3; l++) {
                if (l == k || (i == 1 && k == first_color)) continue;
                ans = min(ans, dp[i-1][l]);
            }

            dp[i][k] = happy[i][k] + ans;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 3; i++) {
        if (i != first_color) {
            ans = min(ans, dp[n-1][i]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> happy(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            scanf("%d", &happy[i][k]);
        }
    }

    cout << min({
        solve(happy, n, 0),
        solve(happy, n, 1),
        solve(happy, n, 2)
    }) << endl;

    return 0;
}