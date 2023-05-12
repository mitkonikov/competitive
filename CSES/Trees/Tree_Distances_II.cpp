#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
vector<vector<int>> adj;
vector<int> subsize;
vector<ll> ans;

int dfs_sz(int u, int p = -1) {
    subsize[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        subsize[u] += dfs_sz(v, u);
    }
    return subsize[u];
}

ll dfs(int u, int p = -1) {
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        auto count = dfs(v, u);
        ans[u] += count + subsize[v];
    }
    return ans[u];
}

void dfs2(int u, int p = -1, ll push = 0) {
    push += (N - subsize[u]);
    ans[u] += push;
    int sz = adj[u].size();
    vector<ll> pref(sz), suff(sz);
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        pref[i] = suff[i] = ans[v] + subsize[v];
    }
    for (int i = 1; i < sz; i++) {
        pref[i] = pref[i] + pref[i-1];
    }
    for (int i = sz - 2; i >= 0; i--) {
        suff[i] = suff[i] + suff[i+1];
    }
    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        ll p = (i ? pref[i-1] : 0);
        ll s = (i == sz - 1 ? 0 : suff[i+1]);
        dfs2(v, u, push + p + s);
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    ans.resize(N);
    subsize.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(0);
    dfs(0);
    dfs2(0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    } cout << endl;
    return 0;
}