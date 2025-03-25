#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        const int N = n;
        const int M = edges.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(N);
        vector<int> root(N);
        vector<int> count_vert(N);
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                root[top] = i;
                count_vert[i]++;
                for (auto v: adj[top]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        vector<int> count_edges(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            count_edges[root[u]]++;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (count_vert[i] == 0) continue;
            if ((long long)count_vert[i] * (count_vert[i] - 1) / 2 == count_edges[i]) ans++;
        }
        return ans;
    }
};