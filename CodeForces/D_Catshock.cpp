#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    vector<int> depth(N);
    auto dfs = [&](auto&& self, int u, int p, int d) -> int {
        depth[u] = d;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            self(self, v, u, d + 1);
        }
        return 0;
    };
    dfs(dfs, N - 1, -1, 0);
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&depth](int a, int b) {
        return depth[a] > depth[b];
    });
    int cat_depth = depth[0];
    vector<pair<int, int>> ans;
    for (int i = 0; i < N - 1; i++) {
        int u = idx[i];
        int cur_depth = depth[u];
        if (cur_depth % 2 == cat_depth % 2) {
            cat_depth++;
            ans.push_back({ 1, 0 });
        } else {
            ans.push_back({ 1, 0 });
            ans.push_back({ 1, 0 });
        }
        ans.push_back({ 2, u + 1 });
    }
    cout << ans.size() << endl;
    for (auto& [t, x] : ans) {
        if (t == 1) cout << t << endl;
        else cout << t << " " << x << endl;
    }
    cout << endl;
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