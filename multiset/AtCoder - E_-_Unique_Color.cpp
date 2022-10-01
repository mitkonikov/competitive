#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> c;
vector<vector<int>> adj;
multiset<int> current_colors;
vector<bool> ans;

inline void eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
    }
}

void dfs(int node, int parent) {
    if (!current_colors.count(c[node])) {
        ans[node] = true;
    }

    current_colors.insert(c[node]);
    for (auto v: adj[node]) {
        if (v == parent) continue;
        dfs(v, node);
    }

    eraseOne(current_colors, c[node]);
}

int main() {
    int n;
    cin >> n;
    c.resize(n);
    adj.resize(n);
    ans.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        if (ans[i]) cout << i + 1 << endl;
    }

    cout << flush;
    return 0;
}