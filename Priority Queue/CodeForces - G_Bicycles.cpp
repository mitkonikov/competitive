#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    vector<int> bikes(N);
    for (int i = 0; i < N; i++) cin >> bikes[i];
    struct D {
        ll cost, slowness, node;
        bool operator>(const D& other) const {
            if (cost == other.cost) return slowness > other.slowness;
            return cost > other.cost;
        }
    };
    priority_queue<D, vector<D>, greater<D>> pq;
    pq.push({ 0, bikes[0], 0 });
    const ll INF = 1e18;
    vector<vector<ll>> dist(N, vector<ll>(1010, INF));
    while (!pq.empty()) {
        auto [cost, slowness, u] = pq.top();
        pq.pop();
        slowness = min(slowness, (ll)bikes[u]);

        for (auto [v, w]: adj[u]) {
            if (dist[v][slowness] > cost + w * slowness) {
                dist[v][slowness] = cost + w * slowness;
                pq.push({ dist[v][slowness], slowness, v });
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < 1000; i++) {
        ans = min(ans, dist[N - 1][i]);
    }
    cout << ans << endl;
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