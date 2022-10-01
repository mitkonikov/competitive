#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<int> sz, cpar;
vector<int> Rank;
vector<bool> vis;
int N;

void dfs(int n, int p=-1) {
    sz[n] = 1;
    for (int v : adj[n]) if (v != p && !vis[v]) {
        dfs(v, n);
        sz[n] += sz[v];
    }
}

int centroid(int n) {
    dfs(n);
    int num = sz[n];
    int p = -1;
    do {
        int nxt = -1;
        for (int v : adj[n]) if (v != p && !vis[v]) {
            if (2 * sz[v] > num)
                nxt = v;
        }
        p = n, n = nxt;
    } while (~n);
    return p;
}

void centroid_decomp(int n=0, int p=-1, int r = 0) {
    int c = centroid(n);
    vis[c] = true;
    cpar[c] = p;
    Rank[c] = r;
    for (int v : adj[c]) if (!vis[v]) {
        centroid_decomp(v, c, r+1);
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    sz.resize(N);
    cpar.resize(N);
    vis.resize(N);
    Rank.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

	centroid_decomp();
    bool ok = true;
    for (int i = 0; i < N && ok; i++) if (Rank[i] >= 26) ok = false;
    if (!ok) {
        cout << "Impossible!" << endl;
        return 0;
    }
    
    for (int i = 0; i < N; i++) cout << (char)('A' + Rank[i]) << " ";
    cout << endl;
    return 0;
}