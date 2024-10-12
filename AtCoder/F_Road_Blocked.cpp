#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int u, v;
    ll c;

    void read() {
        cin >> u >> v >> c;
        u--; v--;
    }
};

struct query {
    int t, r, x, y;
    
    void read() {
        cin >> t;
        if (t == 1) {
            cin >> r;
            r--;
        } else {
            cin >> x >> y;
            x--; y--;
        }
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<edge> edges(M);
    for (int i = 0; i < M; i++) {
        edges[i].read();
    }
    vector<bool> closed(M, false);
    vector<query> q(Q);
    for (int i = 0; i < Q; i++) {
        q[i].read();
        if (q[i].t == 1) closed[q[i].r] = true;
    }
    const int MX = 10;
    vector<vector<ll>> dist(N + MX, vector<ll>(N + MX, 1e18));
    for (int i = 0; i < M; i++) {
        if (closed[i]) continue;
        dist[edges[i].u][edges[i].v] = edges[i].c;
        dist[edges[i].v][edges[i].u] = edges[i].c;
    }
    for (int i = 0; i < N + MX; i++) {
        dist[i][i] = 0;
    }
    int NN = N + MX;
    for (int k = 0; k < NN; k++) {
        for (int i = 0; i < NN; i++) {
            for (int j = 0; j < NN; j++) {
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                );
            }
        }
    }
    vector<ll> ans;
    for (int i = Q - 1; i >= 0; i--) {
        if (q[i].t == 1) {
            int u = edges[q[i].r].u;
            int v = edges[q[i].r].v;
            int c = edges[q[i].r].c;
            for (int i = 0; i < NN; i++) {
                for (int j = 0; j < NN; j++) {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][u] + c + dist[v][j]
                    );
                }
            }
            for (int i = 0; i < NN; i++) {
                for (int j = 0; j < NN; j++) {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][v] + c + dist[u][j]
                    );
                }
            }
        } else if (q[i].t == 2) {
            ll d = dist[q[i].x][q[i].y];
            ans.push_back((d == 1e18 ? -1 : d));
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}