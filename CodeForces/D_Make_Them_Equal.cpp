#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int dp[1010];
int mx_dp = 0;
 
void testCase() {
    int n, k;
    cin >> n >> k;
 
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
 
    k = min(k, mx_dp * n);

    vector<vector<int>> dp_knap(n+1, vector<int>(k+1, 0));
    vector<int> weights(n+1), values(n+1);
 
    int add = 0;

    for (int i = 1; i <= n; i++) {
        if (dp[b[i-1]] == 0) {
            weights[i] = k + 100;
            values[i] = 0;
            add += c[i-1];
            continue;
        }
 
        weights[i] = dp[b[i-1]];
        values[i] = c[i-1];
    }
 
    int W = k;
 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp_knap[i][w] = 0;
            else if (w - weights[i] >= 0) {
                // you can take that item
                dp_knap[i][w] = max(dp_knap[i-1][w], dp_knap[i-1][w-weights[i]] + values[i]);
            } else {
                dp_knap[i][w] = dp_knap[i-1][w];
            }
        }
    }
 
    cout << add + dp_knap[n][k] << endl;
}
 
int main() {
    for (int i = 0; i < 1010; i++) {
        dp[i] = 1e9+100;
    }
 
    dp[1] = 0;
    for (int a = 1; a <= 1000; a++) {
        for (int x = 1; x <= 1000; x++) {
            if (a + (a / x) <= 1002)
                dp[a + (a / x)] = min(dp[a + (a / x)], dp[a] + 1);
        }
    }

    for (int i = 1; i <= 1002; i++) {
        mx_dp = max(mx_dp, dp[i]);
    }
 
    int t;
    cin >> t;
 
    while (t--) {
        testCase();
    }
 
    cout << flush;
    return 0;
}