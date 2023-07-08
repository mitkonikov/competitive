#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<int> ins;
int ans = 0;

void dfs(int u, int longest = -1) {
    if (ins[u] != -1) {
        longest = max(longest, depth[u] + ins[u]);
    }

    if (longest >= depth[u]) ans++;

    for (int v: adj[u]) {
        dfs(v, longest);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    adj.resize(N);
    ins.resize(N, -1);
    depth.resize(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        depth[i] = depth[p] + 1;
    }
    for (int i = 0; i < Q; i++) {
        int u, g;
        cin >> u >> g;
        u--;
        ins[u] = max(ins[u], g);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}