#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int cost, u, v;
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
        int x = find_set(a);
        int y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> c(n);
    vector<edge> edges(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        edges[i] = { c[i], i, x[i] };
    }
    sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
        return (a.cost > b.cost);
    });
    dsu dsu(n);
    for (int i = 0; i < n; i++) {
        if (dsu.are_same(edges[i].u, edges[i].v)) {
            ans = ans + edges[i].cost;
        } else {
            dsu.merge(edges[i].u, edges[i].v);
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}