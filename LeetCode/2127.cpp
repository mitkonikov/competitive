#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> st;
    vector<bool> visited;
    vector<int> f;

    int dfs1(int u, int p, int depth) {
        visited[u] = true;
        st[u] = depth;
        if (visited[f[u]]) {
            auto it = st.find(f[u]);
            if (it != st.end()) return depth - it->second + 1;
            return 0;
        }
        return dfs1(f[u], u, depth + 1);
    }

    int dfs2(int u, vector<vector<int>>& rev) {
        int mx = 1;
        for (auto v : rev[u]) {
            mx = max(mx, dfs2(v, rev) + 1);
        }
        return mx;
    }

    int maximumInvitations(vector<int>& favorite) {
        // largest cycle or largest path where f[u] == v and f[v] == u
        const int N = favorite.size();
        st.clear();
        visited.clear();
        visited.resize(N);
        f = favorite;
        int ans = 1;
        // cycle
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                const int cycle_len = dfs1(i, -1, 1);
                ans = max(ans, cycle_len);
                st.clear();
            }
        }
        // second case where f[f[i]] == i
        vector<vector<int>> rev(N);
        for (int i = 0; i < N; i++) {
            rev[f[i]].push_back(i);
        }
        int second_ans = 0;
        visited.clear();
        visited.resize(N);
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (f[f[i]] == i) {
                visited[i] = true;
                visited[f[i]] = true;
                ans = max(ans, 2);
                int best1 = 0;
                for (auto rv : rev[i]) {
                    if (rv == f[i]) continue;
                    best1 = max(best1, dfs2(rv, rev));
                }
                int best2 = 0;
                for (auto rv : rev[f[i]]) {
                    if (rv == i) continue;
                    best2 = max(best2, dfs2(rv, rev));
                }
                second_ans += best1 + best2 + 2;
            }
        }
        ans = max(ans, second_ans);
        return ans;
    }
};