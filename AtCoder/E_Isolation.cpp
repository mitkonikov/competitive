#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> adj(N);
    int ans = N;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (adj[u].empty()) ans--;
            if (adj[v].empty()) ans--;
            adj[u].insert(v);
            adj[v].insert(u);
        } else {
            int u;
            cin >> u;
            u--;
            bool non_empty = !adj[u].empty();
            for (auto v: adj[u]) {
                adj[v].erase(u);
                if (adj[v].empty()) ans++;
            }
            adj[u].clear();
            if (non_empty) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}