#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> deg(N);
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 1) {
            auto v = adj[i][0];
            y = deg[v];
            for (auto VV: adj[v]) {
                if (deg[VV] > 1) {
                    x = deg[VV];
                    break;
                }
            }
            break;
        }
    }

    cout << x << " " << y - 1 << endl;
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