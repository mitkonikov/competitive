#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> dp, dp2;

void dfs1(int u, int p) {
    dp[u] = (int)adj[u].size() - (p != -1);
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] = max(dp[u], (int)adj[u].size() - 1 - (p != -1) + dp[v]);
    }
}

void dfs2(int u, int p) {
    dp2[u] = dp[u] + (p != -1);
    vector<int> sorted;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
        sorted.push_back(dp[v]);
    }
    sort(sorted.rbegin(), sorted.rend());
    if (sorted.size() >= 2) {
        dp2[u] = max(dp2[u], sorted[0] + sorted[1] + (int)adj[u].size() - 2);
    } else if (sorted.size() == 1) {
        dp2[u] = max(dp2[u], sorted[0] + (int)adj[u].size() - 1);
    }
}

void testCase() {
    int N;
    cin >> N;
    adj.clear();
    dp.clear();
    dp2.clear();
    adj.resize(N);
    dp.resize(N);
    dp2.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    cout << *max_element(dp2.begin(), dp2.end()) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}