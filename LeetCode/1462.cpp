#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<set<int>> req;
    vector<vector<int>> adj;
    vector<bool> visited;
    
    void dfs(int u) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) dfs(v);
            for (auto el: req[v]) req[u].insert(el);
            req[u].insert(v);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.clear();
        adj.resize(numCourses);
        req.clear();
        req.resize(numCourses);
        visited.clear();
        visited.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) continue;
            dfs(i);
        }
        const int Q = queries.size();
        vector<bool> ans(Q);
        for (int q = 0; q < Q; q++) {
            int u = queries[q][0];
            int v = queries[q][1];
            ans[q] = req[v].count(u);
        }
        return ans;
    }
};