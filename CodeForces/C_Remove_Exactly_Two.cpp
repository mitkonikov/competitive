#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> best_from_childs, best_me;
vector<int> ans;

void dfs1(int u, int p) {
    best_me[u] = adj[u].size() - (p != -1);
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
    }

    for (auto v : adj[u]) {
        if (v == p) continue;
        best_from_childs[u] = max(best_from_childs[u], best_me[v]);
        best_from_childs[u] = max(best_from_childs[u], best_from_childs[v]);
    }
}

void dfs2(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
    vector<int> bests, bests_him;
    for (auto v : adj[u]) {
        if (v == p) continue;
        bests.push_back(best_from_childs[v]);
        bests_him.push_back(best_me[v]);
    }
    // delete both inside
    sort(bests.rbegin(), bests.rend());
    if (bests.size() >= 2 && bests[0] >= 0 && bests[1] >= 0) {
        ans[u] = max(ans[u], bests[0] + bests[1] + 1);
    }
    if (bests.size() >= 1 && bests[0] >= 0) {
        ans[u] = max(ans[u], bests[0] + (int)adj[u].size());
    }
    // delete both direct children
    sort(bests_him.rbegin(), bests_him.rend());
    if (bests_him.size() >= 2) {
        ans[u] = max(ans[u], bests_him[0] + bests_him[1] + 1);
    }
    if (bests_him.size() >= 1) {
        ans[u] = max(ans[u], bests_him[0] + (int)adj[u].size() - 1);
    }

    // one child and one inside
    vector<int> pref(adj[u].size(), 0), suff(adj[u].size(), 0);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v != p) pref[i] = best_from_childs[v];
        if (i > 0) pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        if (v != p) suff[i] = best_from_childs[v];
        if (i + 1 < adj[u].size()) suff[i] = max(suff[i], suff[i + 1]);
    }
    if (adj[u].size() - (p != -1) >= 2) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (v == p) continue;
            int best = 0;
            if (i > 0) best = max(best, pref[i - 1]);
            if (i + 1 < adj[u].size()) best = max(best, suff[i + 1]);
            ans[u] = max(ans[u], best + best_me[v] + 1);
        }
    }
}

void testCase() {
    int N;
    cin >> N;
    adj.clear();
    adj.resize(N);
    best_from_childs.clear();
    best_from_childs.resize(N, -1);
    best_me.clear();
    best_me.resize(N, 0);
    ans.clear();
    ans.resize(N, 0);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    int mx = 0;
    for (int i = 0; i < N; i++) {
        mx = max(mx, ans[i]);
    }
    cout << mx << endl;
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