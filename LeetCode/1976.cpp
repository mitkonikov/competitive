#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        const int N = n;
        const int M = roads.size();
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<int> ways(N);
        vector<ll> cost(N, 1e18 + 10);
        ways[0] = 1;
        pq.push({ 0, 0 });
        cost[0] = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ll c = top.first;
            int u = top.second;
            if (c > cost[u]) continue;
            for (auto [v, w]: adj[u]) {
                if (c + w == cost[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                } else if (c + w < cost[v]) {
                    cost[v] = c + w;
                    ways[v] = ways[u];
                    pq.push({ cost[v], v });
                }
            }
        }
        return ways[N-1];
    }
};