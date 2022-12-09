#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[10100][2];
vector<int> a;

int dfs(int stones, int player) {
    if (dp[stones][player] != -1) return dp[stones][player];
    int best = (player == 0 ? INT_MIN : INT_MAX);
    bool taken = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > stones) break;
        if (player == 0) best = max(best, dfs(stones - a[i], 1) + a[i]);
        if (player == 1) best = min(best, dfs(stones - a[i], 0));
        taken = true;
    }
    if (!taken) return dp[stones][player] = 0;
    return dp[stones][player] = best;
}

int main() {
    memset(dp, -1, sizeof dp);
    int n, k;
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << dfs(n, 0) << endl;
    return 0;
}