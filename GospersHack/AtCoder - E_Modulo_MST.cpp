#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void GospersHack(int n, int k, function<void(ll)> f) {
    ll set = (1 << k) - 1;
    ll limit = (1 << n);
    while (set < limit) {
        f(set);
        ll c = set & - set;
        ll r = set + c;
        set = (((r ^ set) >> 2) / c) | r;
    }
}

struct dsu {
    vector<int> parent;
    int comps = 0;

    dsu(int n) {
        parent.resize(n, -1);
        comps = n;
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    int merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        comps--;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

int main() {
    int N, M;
    ll K;
    cin >> N >> M;
    cin >> K;
    struct edge { ll u, v, w; };
    vector<edge> edges(M);
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = { u, v, w };
    }
    ll ans = LLONG_MAX;
    GospersHack(M, N - 1, [&](ll mask) {
        ll sum = 0;
        dsu dsu(N);
        for (int i = 0; i < M; i++) {
            if ((1LL << i) & mask) {
                sum = (sum + edges[i].w) % K;
                dsu.merge(edges[i].u, edges[i].v);
            }
        }
        if (dsu.comps == 1) ans = min(ans, sum);
    });
    cout << ans << endl;
    return 0;
}