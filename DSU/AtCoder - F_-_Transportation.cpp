#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct cost {
    int c, u, v;
    bool operator<(const cost& other) const {
        return make_pair(c, v) < make_pair(other.c, other.v);
    }
};

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n, -1);
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
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

ll solve(int n, vector<cost> costs) {
    sort(costs.begin(), costs.end());
    dsu dsu(n + 2);
    ll ans = 0;
    for (int i = 0; i < (int)costs.size(); i++) {
        if (dsu.are_same(costs[i].u, costs[i].v)) {
            continue;
        }
        dsu.merge(costs[i].u, costs[i].v);
        ans += costs[i].c;
    }
    return (dsu.size(0) >= n ? ans : LLONG_MAX);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> air(n), water(n);
    for (int i = 0; i < n; i++) cin >> air[i];
    for (int j = 0; j < n; j++) cin >> water[j];
    vector<cost> costs;
    costs.reserve(2 * n + m);
    for (int i = 0; i < m; i++) {
        int u, v, z;
        cin >> u >> v >> z;
        u--; v--;
        costs.push_back({ z, u, v });
    }
    ll ans = LLONG_MAX;
    for (int iter = 0; iter < 4; iter++) {
        vector<cost> new_costs(costs);
        if (iter & 1) for (int i = 0; i < n; i++) new_costs.push_back({ air[i], i, n });
        if (iter & 2) for (int i = 0; i < n; i++) new_costs.push_back({ water[i], i, n + 1});
        ans = min(ans, solve(n, new_costs));
    }
    cout << ans << endl;
    return 0;
}