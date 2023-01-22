#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool umin(ll& a, ll b) {
    if (b <= a) {
        a = b;
        return true;
    }
    return false;
}

inline bool umax(ll& a, ll b) {
    if (b >= a) {
        a = b;
        return true;
    }
    return false;
}

const int INF = 1e9 + 10;

int main() {
    int N;
    cin >> N;
    vector<ll> val(N);
    for (int i = 0; i < N; i++) cin >> val[i];
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'Y') dist[i][j] = 1;
        }
    }
    vector<vector<ll>> sou(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
        sou[i][i] = val[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            sou[i][j] = val[i] + val[j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ll bef = dist[i][j];
                ll aft = dist[i][k] + dist[k][j];
                if (aft < bef) {
                    dist[i][j] = aft;
                    sou[i][j] = sou[i][k] + sou[k][j] - val[k];
                } else if (aft == bef && aft < INF) {
                    umax(sou[i][j], sou[i][k] + sou[k][j] - val[k]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (dist[u][v] == INF) {
            cout << "Impossible" << endl;
            continue;
        }
        cout << dist[u][v] << " " << sou[u][v] << endl;
    }

    return 0;
}