#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> where;
    vector<int> values;
    vector<int> pointer;
    vector<int> depth;
    vector<int> length;
    vector<int> next;
    int ans_len = 0;
    int ans_nodes = 1e9;

    void update_ans(int len, int nodes) {
        if (len == ans_len) {
            ans_len = len;
            if (nodes < ans_nodes) {
                ans_nodes = nodes;
            }
        } else if (len > ans_len) {
            ans_len = len;
            ans_nodes = nodes;
        }
    }

    void dfs1(int u, int par, int d, int l) {
        depth[u] = d;
        length[u] = l;
        if (where[values[u]].size()) {
            pointer[u] = where[values[u]].back();
        }
        where[values[u]].push_back(u);
        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (v == par) continue;
            dfs1(v, u, d + 1, l + w);
        }
        where[values[u]].pop_back();
    }

    void dfs2(int u, int par, int prev = -1) {
        if (pointer[u] != -1) {
            if (prev == -1) {
                prev = pointer[u];
            } else {
                if (depth[u] - depth[prev] > depth[u] - depth[pointer[u]]) {
                    prev = pointer[u];
                }
            }
        }

        if (prev == -1) {
            update_ans(length[u], depth[u] + 1);
        } else {
            if (next[prev] != -1) {
                update_ans(length[u] - length[next[prev]], depth[u] - depth[next[prev]] + 1);
            }
        }
        
        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (v == par) continue;
            next[u] = v;
            dfs2(v, u, prev);
            next[u] = -1;
        }
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int N = nums.size();
        int M = edges.size();
        adj.clear();
        adj.resize(N);
        values = nums;
        where.clear();
        where.resize(5e4 + 1000);
        pointer.clear();
        pointer.resize(N, -1);
        depth.clear();
        depth.resize(N, 0);
        next.clear();
        next.resize(N, -1);
        length.clear();
        length.resize(N, 0);
        ans_len = 0;
        ans_nodes = 1e9;
        
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int l = edges[i][2];
            adj[u].push_back({ v, l });
            adj[v].push_back({ u, l });
        }

        dfs1(0, -1, 0, 0);
        dfs2(0, -1);
        return { ans_len, ans_nodes };
    }
};