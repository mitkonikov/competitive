#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int u, v, b, c;
    void read() {
        cin >> u >> v >> b >> c;
        u--; v--;
    }
};

vector<vector<edge>> adj;

inline void umax(double& a, double b) {
    if (b > a) a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        edge e;
        e.read();
        adj[e.u].push_back(e);
    }
    double L = 0, R = 1e10;
    while (R - L > 1e-10) {
        double M = (R + L) / 2;

        vector<double> dp(N, -1e14);
        dp[0] = 0;
        for (int u = 0; u < N; u++) {
            for (auto& edge: adj[u]) {
                double w = edge.b - edge.c * M;
                umax(dp[edge.v], dp[u] + w);
            }
        }

        if (dp[N-1] >= 0) {
            L = M;
        } else {
            R = M;
        }
    }
    cout << fixed << setprecision(15) << R << endl;
    return 0;
}