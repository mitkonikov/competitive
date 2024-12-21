#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> subtree;
int ans = -1e9;

// turns out that I didn't need this DFS
void dfs1(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree[u] += subtree[v];
    }
    subtree[u] += 1;
}

void dfs2(int u, int p) {
    vector<pair<int, int>> s;
    for (auto v: adj[u]) {
        s.push_back({ (int)adj[v].size() - 1, v });
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        ans = max(ans, (s[i].first + 1) * ((int)s.size() - i) + 1);
    }
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    subtree.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    cout << N - ans << endl;
    return 0;
}