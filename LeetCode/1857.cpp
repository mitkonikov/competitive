#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int N = colors.size();
        const int M = edges.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            const int u = edges[i][0];
            const int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool> visited(N);
        vector<bool> instack(N);
        vector<int> order;
        auto dfs = [&](auto&& self, int u) {
            if (instack[u]) return -1;
            if (visited[u]) return 0;
            visited[u] = true;
            instack[u] = true;
            for (auto v : adj[u]) {
                const int res = self(self, v);
                if (res < 0) return res;
            }
            instack[u] = false;
            order.push_back(u);
            return 0;
        };
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (dfs(dfs, i) < 0) {
                return -1;
            }
        }
        vector<vector<int>> dp(N, vector<int>(26, 0));
        assert(order.size() == N);
        int ans = 1;
        for (int i = 0; i < N; i++) {
            int u = order[i];
            dp[u][colors[u] - 'a'] = 1;
            for (int c = 0; c < 26; c++) {
                for (auto v: adj[u]) {
                    dp[u][c] = max(dp[u][c], dp[v][c] + (colors[u] - 'a' == c));
                    ans = max(ans, dp[u][c]);
                }
            }
        }
        return ans;
    }
};