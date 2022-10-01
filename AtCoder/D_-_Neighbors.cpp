#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 2) {
            ok = false;
            break;
        }
    }

    vector<bool> visited(n, false);

    for (int i = 0; i < n && ok; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        if (adj[i].empty()) continue;

        int L = *adj[i].begin();
        visited[L] = true;
        adj[i].erase(L);
        int prL = i;
        while (true) {
            adj[L].erase(prL);
            prL = L;
            if (adj[L].empty()) break;
            L = *adj[L].begin();
            if (visited[L]) {
                ok = false;
                break;
            }
            visited[L] = true;
        }

        if (adj[i].empty()) continue;
        int R = *adj[i].begin();
        adj[i].erase(R);
        visited[R] = true;
        int prR = i;
        while (true) {
            adj[R].erase(prR);
            prR = R;
            if (adj[R].empty()) break;
            R = *adj[R].begin();
            if (visited[R]) {
                ok = false;
                break;
            }
            visited[R] = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}