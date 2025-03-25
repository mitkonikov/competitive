#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        const int N = n;
        const int M = edges.size();
        const int Q = query.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
        vector<bool> visited(N);
        vector<int> ands;
        vector<int> root(N);
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            int bits = (1 << 30) - 1;
            while (!q.empty()) {
                int top = q.front();
                q.pop();
                root[top] = (int)ands.size();
                for (auto [v, w] : adj[top]) {
                    bits &= w;
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            ands.push_back(bits);
        }
        vector<int> ans(Q);
        for (int i = 0; i < Q; i++) {
            int s = query[i][0];
            int t = query[i][1];
            if (root[s] != root[t]) {
                ans[i] = -1;
                continue;
            }
            ans[i] = ands[root[s]];
        }
        return ans;
    }
};