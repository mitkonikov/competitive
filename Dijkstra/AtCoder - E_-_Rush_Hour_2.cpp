#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    struct edge {
        int to;
        ll c, d;
    };
    vector<vector<edge>> adj(N);
    for (int i = 0; i < M; i++) {
        int U, V, C, D;
        cin >> U >> V >> C >> D;
        U--; V--;
        adj[U].push_back({ V, C, D });
        adj[V].push_back({ U, C, D });
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(N, LLONG_MAX);

    dist[0] = 0;
    pq.push({ 0, 0 });

    auto calc = [&](edge e, ll cost) {
        auto f = [&](ll i) {
            return (cost + e.c + (e.d / (cost + 1 + i)) + i);
        };
        ll a = max(0LL, (ll)sqrt(e.d) - cost - 1);
        ll best = f(a);
        for (int i = max(0LL, a - 1LL); i <= a + 1; i++) {
            best = min(best, f(i));
        }
        return best;
    };

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        if (cost > dist[u]) continue;

        for (auto edge: adj[u]) {
            auto COST = calc(edge, dist[u]);
            if (dist[edge.to] > COST) {
                dist[edge.to] = COST;
                pq.push({ dist[edge.to], edge.to });
            }
        }
    }

    cout << (dist[N - 1] == LLONG_MAX ? -1 : dist[N - 1]) << endl;
    return 0;
}