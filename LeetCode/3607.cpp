#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        const int M = connections.size();
        vector<vector<int>> adj(c);
        for (int i = 0; i < M; i++) {
            int u = connections[i][0] - 1;
            int v = connections[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> root(c, -1);
        for (int i = 0; i < c; i++) {
            if (root[i] != -1) continue;
            root[i] = i;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (auto& v : adj[t]) {
                    if (root[v] == -1) {
                        root[v] = i;
                        q.push(v);
                    }
                }
            }
        }
        vector<set<int>> online(c);
        for (int i = 0; i < c; i++) {
            online[root[i]].insert(i);
        }
        const int Q = queries.size();
        vector<int> ans;
        for (int i = 0; i < Q; i++) {
            int t = queries[i][0];
            int x = queries[i][1] - 1;
            if (t == 1) {
                if (online[root[x]].count(x)) ans.push_back(x + 1);
                else ans.push_back((online[root[x]].size() ? *online[root[x]].begin() + 1 : -1));
            } else {
                online[root[x]].erase(x);
            }
        }
        return ans;
    }
};