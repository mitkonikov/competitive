#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] = true;
        adj[v][u] = true;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (adj[i][j] && adj[j][k] && adj[k][i]) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    cout << flush;
    return 0;
}