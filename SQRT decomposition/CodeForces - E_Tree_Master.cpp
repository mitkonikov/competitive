#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> A;
vector<int> P;
vector<vector<int>> adj;
vector<int> depth;
vector<bool> precomputed;
map<pair<int, int>, ll> dp;
vector<vector<int>> depth_based;

void dfs1(int u, int d) {
    depth[u] = d;
    depth_based[depth[u]].push_back(u);
    for (auto v: adj[u]) {
        dfs1(v, d + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    A.resize(N + 1);
    P.resize(N + 1);
    adj.resize(N + 1);
    depth.resize(N + 1);
    depth_based.resize(N + 100);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
        adj[P[i]].push_back(i);
    }
    dfs1(1, 0);
    int max_depth = *max_element(depth.begin(), depth.end()) + 10;
    precomputed.resize(max_depth);
    depth_based.resize(max_depth);
    
    bool bDEBUG = false;
    int MAGIC = 333;
    if (max_depth > MAGIC || bDEBUG) {
        vector<int> count(max_depth);
        for (int i = 1; i <= N; i++) count[depth[i]]++;
        for (int i = 0; i < max_depth; i += MAGIC) {
            vector<pair<int, int>> c;
            c.reserve(MAGIC);
            for (int j = i; j < min(max_depth, i + MAGIC); j++) {
                c.push_back({ count[j], j });
            }
            sort(c.begin(), c.end());
            int best_depth = c[0].second;
            if (bDEBUG) best_depth = 2;
            for (int k = 0; k < depth_based[best_depth].size(); k++) {
                for (int l = k; l < depth_based[best_depth].size(); l++) {
                    int u, ui, v, vi;
                    u = ui = depth_based[best_depth][k];
                    v = vi = depth_based[best_depth][l];
                    ll ans = 0;
                    while (u != 0 && v != 0) {
                        if (precomputed[depth[u]]) {
                            ans += dp[{u, v}];
                            break;
                        }
                        ans += (ll)A[u] * A[v];
                        u = P[u];
                        v = P[v];
                    }
                    dp[{ min(ui, vi), max(ui, vi) }] = ans;
                }
            }
            precomputed[best_depth] = true;
        }
    }

    for (int j = 0; j < Q; j++) {
        int u, v;
        cin >> u >> v;
        // assert(depth[u] == depth[v]);
        ll ans = 0;
        while (u != 0 && v != 0) {
            if (precomputed[depth[u]]) {
                ans += dp[{ min(u, v), max(u, v) }];
                break;
            }
            ans += (ll)A[u] * A[v];
            u = P[u];
            v = P[v];
        }
        cout << ans << endl;
    }
    return 0;
}