#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> adj(N);
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U--; V--;
        adj[U].push_back({ V, W });
        adj[V].push_back({ U, W });
    }
    ll ans = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (auto& [v, w] : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            ll init = A[u];
            A[u] += A[v];
            ll diff = abs(A[u] - init);
            ans += diff * w;
        }
    };
    dfs(dfs, 0, -1);
    cout << ans << endl;
    return 0;
}