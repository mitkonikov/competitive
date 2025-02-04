#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& ans) {
        visited[u] = true;
        bool fail = false;
        for (auto v: graph[u]) {
            if (visited[v]) {
                if (ans[v] == 0) fail = true;
            }
            else if (!dfs(v, graph, visited, ans)) {
                fail = true;
            }
        }
        return ans[u] = !fail;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<bool> visited(N);
        vector<bool> ans(N);
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, ans);
            }
        }
        vector<int> acc;
        for (int i = 0; i < N; i++) {
            if (ans[i]) acc.push_back(i);
        }
        return acc;
    }
};