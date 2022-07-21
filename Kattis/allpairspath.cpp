#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        int n, m, q;
        cin >> n >> m >> q;

        if (n == 0) break;

        const int INF = 1e6;

        vector<vector<int>> mat(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) mat[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            mat[u][v] = min(mat[u][v], w);
        }
        
        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] > mat[i][k] + mat[k][j] && mat[i][k] < INF && mat[k][j] < INF) {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != -INF) {
                    for (int k = 0; k < n; k++) {
                        if (mat[k][k] < 0 && mat[i][k] != INF && mat[k][j] != INF) {
                            mat[i][j] = -INF;
                        }
                    }
                }
            }
        }

        while (q--) {
            int u, v;
            cin >> u >> v;

            if (mat[u][v] == -INF) {
                cout << "-Infinity\n";  
            } else if (mat[u][v] == INF) {
                cout << "Impossible\n";
            } else {
                cout << mat[u][v] << "\n";
            }
        }

        cout << "\n";
    }

    cout << flush;

    return 0;
}