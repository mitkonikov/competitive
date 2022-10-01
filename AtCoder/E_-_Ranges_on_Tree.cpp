#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

vector<pair<int, int>> interval;

int timer = 0;

void dfs(int node, int parent) {
    interval[node].first = timer;
    
    bool f = false;
    for (auto u: adj[node]) {
        if (u == parent) continue;
        dfs(u, node);
        timer++;
        f = true;
    }

    if (f) timer--;

    interval[node].second = timer;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    interval.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << interval[i].first + 1 << " " << interval[i].second + 1 << endl;
    }
    
    return 0;
}