#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> st;
    vector<bool> in_stack;
    vector<vector<int>> adj;
    vector<bool> in_cycle;

    void dfs(int u, int p) {
        in_stack[u] = true;
        st.push_back(u);

        for (auto v : adj[u]) {
            if (v == p) continue;
            if (in_stack[v]) {
                for (int ptr = st.size() - 1; ptr >= 0; ptr--) {
                    in_cycle[st[ptr]] = true;
                    if (st[ptr] == v) break;
                }
                continue;
            }
            dfs(v, u);
        }

        in_stack[u] = false;
        st.pop_back();
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        st.clear();
        st.reserve(N);
        in_stack.clear();
        in_stack.resize(N);
        adj.clear();
        adj.resize(N);
        in_cycle.clear();
        in_cycle.resize(N);
        for (int i = 0; i < N; i++) {
            const int u = edges[i][0] - 1;
            const int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        for (int i = N - 1; i >= 0; i--) {
            const int u = edges[i][0] - 1;
            const int v = edges[i][1] - 1;
            if (in_cycle[u] && in_cycle[v]) {
                return { u + 1, v + 1 };
            }
        }
        return { -1, -1 };
    }
};