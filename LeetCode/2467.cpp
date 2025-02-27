#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int N = amount.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < N - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(N), depth(N);
        auto dfs = [&](auto&& dfs, int u, int p, int d) -> void {
            depth[u] = d;
            parent[u] = p;
            for (auto v: adj[u]) {
                if (v == p) continue;
                dfs(dfs, v, u, d + 1);
            }
        };
        dfs(dfs, 0, -1, 0);
        int current = bob;
        while (current > 0) {
            if (depth[current] > depth[bob] / 2) {
                amount[current] = 0;
            } else if (depth[current] * 2 == depth[bob]) {
                amount[current] /= 2;
            }
            current = parent[current];
        }
        vector<int> dp(N, -1e9 - 1000);
        auto dfs2 = [&](auto&& dfs2, int u, int p) -> void {
            for (auto v: adj[u]) {
                if (v == p) continue;
                dfs2(dfs2, v, u);
                dp[u] = max(dp[u], dp[v]);
            }
            
            if (adj[u].size() == 1 && p != -1) {
                dp[u] = amount[u];
            } else {
                dp[u] += amount[u];
            }
        };
        dfs2(dfs2, 0, -1);
        return dp[0];
    }
};