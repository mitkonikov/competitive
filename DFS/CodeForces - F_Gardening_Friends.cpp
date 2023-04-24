#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> height;
vector<int> parent;

int dfs1(int u, int p = -1) {
    height[u] = 0;
    parent[u] = p;
    for (auto v: adj[u]) {
        if (v == p) continue;
        height[u] = max(height[u], dfs1(v, u) + 1);
    }
    return height[u];
}

ll K, C;
ll profit = 0;

void dfs2(int u, int p = -1, int max_height = 0, int depth = 0) {
    vector<int> pref((int)adj[u].size()), suff((int)adj[u].size() + 1, -2);
    for (int i = 0; i < adj[u].size(); i++) {
        if (i) pref[i] = max(pref[i - 1], height[adj[u][i]]);
        else pref[i] = height[adj[u][i]];
    }
    for (int i = adj[u].size() - 1; i >= 0; i--) {
        suff[i] = max(suff[i + 1], height[adj[u][i]]);
    }
    profit = max(profit, K * max_height - C * depth);
    for (int i = 0; i < adj[u].size(); i++) {
        auto v = adj[u][i];
        if (v == p) assert(false);
        int P = (i - 1 >= 0 ? pref[i-1] : -2);
        int S = suff[i+1];
        dfs2(v, u, max({ max_height + 1, P + 2, S + 2 }), depth + 1);
    }
}

void testCase() {
    int N;
    cin >> N >> K >> C;
    adj.clear();
    adj.resize(N);
    profit = 0;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    height.clear();
    height.resize(N);
    parent.clear();
    parent.resize(N);
    dfs1(0);
    // delete parents from adj list
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == parent[i]) {
                adj[i].erase(adj[i].begin() + j);
                break;
            }
        }
    }
    dfs2(0);
    profit = max(profit, K * height[0]);
    cout << profit << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}