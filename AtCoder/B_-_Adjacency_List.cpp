#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 0; i < n; i++) {
        cout << adj[i].size() << " ";
        for (auto el: adj[i]) {
            cout << el + 1 << " ";
        } cout << endl;
    }
    cout << flush;
    return 0;
}