#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        const int N = nums.size();
        const int M = edges.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> x(N), timer_in(N), timer_out(N), depth(N);
        int counter = 0;
        auto dfs = [&](auto&& self, int u, int p, int d) -> void {
            x[u] ^= nums[u];
            timer_in[u] = counter++;
            depth[u] = d;
            for (auto& v : adj[u]) {
                if (v == p) continue;
                self(self, v, u, d + 1);
                x[u] ^= x[v];
            }
            timer_out[u] = counter;
        };
        dfs(dfs, 0, -1, 0);
        int ans = INT_MAX;
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int u = i;
                int v = j;
                if (depth[v] < depth[u]) swap(u, v);
                if (timer_in[v] >= timer_in[u] && timer_out[v] <= timer_out[u]) {
                    // v is under u
                    int x1 = x[v];
                    int x2 = x[u] ^ x[v];
                    int x3 = x[0] ^ x[u];
                    int score = max({ x1, x2, x3 }) - min({ x1, x2, x3 });
                    ans = min(ans, score);
                } else {
                    int x1 = x[u];
                    int x2 = x[v];
                    int x3 = x[0] ^ x[u] ^ x[v];
                    int score = max({ x1, x2, x3 }) - min({ x1, x2, x3 });
                    ans = min(ans, score);
                }
            }
        }
        return ans;
    }
};