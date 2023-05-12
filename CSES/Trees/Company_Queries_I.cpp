#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> jmp;
vector<int> depth;
const int LOG = 20;

void dfs(int u, int p = 0, int d = 0) {
    depth[u] = d;
    jmp[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        jmp[u][i] = jmp[jmp[u][i-1]][i-1];
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

int up(int u, int k) {
    if (depth[u] < k) return -2;
    for (int j = LOG - 1; j >= 0; j--) {
        if ((1 << j) & k) {
            u = jmp[u][j];
        }
    }
    return u;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    adj.resize(N);
    jmp.resize(N, vector<int>(LOG, 0));
    depth.resize(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        cout << up(x, k) + 1 << endl;
    }
    return 0;
}