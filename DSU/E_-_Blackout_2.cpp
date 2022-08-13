#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct edge {
    int u, v;
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

int main() {
    int n, m, e;
    cin >> n >> m >> e;
    auto is_power = [n, m](int station) {
        return (station >= n);
    };
    vector<edge> edges;
    edges.reserve(e);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges.push_back({ min(u, v), max(u, v) });
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    vector<bool> remain(e, true);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        queries[i]--;
        remain[queries[i]] = false;
    }

    dsu dsu(n + 10);
    for (int i = 0; i < e; i++) {
        if (remain[i]) {
            if (is_power(edges[i].v) && is_power(edges[i].u)) {
                continue;
            }

            if (is_power(edges[i].v)) {
                dsu.merge(edges[i].u, n);
            } else {
                dsu.merge(edges[i].u, edges[i].v);
            }
        }
    }
    
    vector<int> ans;
    ans.reserve(q);
    for (int i = q-1; i >= 0; i--) {
        ans.push_back(dsu.size(n));
        int que = queries[i];
        if (is_power(edges[que].v) && is_power(edges[que].u)) {
            continue;
        }

        if (is_power(edges[que].v)) {
            dsu.merge(edges[que].u, n);
        } else {
            dsu.merge(edges[que].u, edges[que].v);
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (auto el: ans) {
        cout << el - 1 << endl;
    }

    cout << flush;
    return 0;
}