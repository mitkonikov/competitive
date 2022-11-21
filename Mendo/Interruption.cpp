// Task: https://mendo.mk/Task.do?id=141

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
    int u, v, c;
    void read() {
        cin >> u >> v >> c;
        u--; v--;
    }
    bool operator<(const edge& other) {
        return (c < other.c);
    }
};

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
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].read();
    }
    sort(edges.begin(), edges.end());
    dsu mst_dsu(n);
    int mst = 0;
    set<int> collection;
    for (int i = 0; i < m; i++) {
        if (!mst_dsu.are_same(edges[i].u, edges[i].v)) {
            mst_dsu.merge(edges[i].u, edges[i].v);
            mst += edges[i].c;
            collection.insert(i);
        }
    }
    int best = INT_MAX;
    for (int i = 0; i < m; i++) {
        dsu new_dsu(n);
        int cost = 0;
        set<int> col;
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            if (!new_dsu.are_same(edges[j].u, edges[j].v)) {
                new_dsu.merge(edges[j].u, edges[j].v);
                cost += edges[j].c;
                col.insert(j);
            }
        }
        if (new_dsu.comps == 1 && col != collection) {
            best = min(best, cost);
        }
    }
    cout << mst << " " << best << endl;
    return 0;
}