#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> ans;

bool dfs(int u, int p, int t) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        if (v == t) {
            ans.push_back(v);
            return true;
        }
        if (dfs(v, u, t)) {
            ans.push_back(v);
            return true;
        }
    }
    return false;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(x, -1, y);
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    for (auto el: ans) cout << el+1 << " ";
    cout << endl;
    cout << flush;
    return 0;
}