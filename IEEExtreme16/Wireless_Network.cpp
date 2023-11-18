#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
    int u, v, cost;

    bool operator<(const edge& e) {
        return (cost < e.cost);
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

    bool merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return false;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        comps--;
        return true;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

vector<vector<int>> adj;

int main() {
    int M;
    cin >> M;

    vector<edge> edges, red_edges;

    unordered_map<string, int> mp;
    int id = 0;
    auto f = [&](string s) {
        auto it = mp.find(s);
        if (it == mp.end()) {
            mp[s] = id;
            id++;
        }
        return mp[s];
    };

    for (int i = 0; i < M; i++) {
        string u, v;
        cin >> u >> v;

        int cost, red;
        cin >> cost >> red;

        if (red) red_edges.push_back({ f(u), f(v), cost });
        else edges.push_back({ f(u), f(v), cost });
    }

    vector<vector<edge>> red_towers(id);
    for (auto edge: red_edges) {
        red_towers[edge.u].push_back(edge);
        red_towers[edge.v].push_back(edge);
    }
    int R = 0;
    vector<int> id_red_towers;
    for (int i = 0; i < id; i++) {
        if (red_towers[i].size()) {
            id_red_towers.push_back(i);
            R++;
        }
    }

    ll ans = LLONG_MAX;
    for (int mask = 0; mask < (1 << R); mask++) {
        vector<edge> e(edges);
        int bit_count = 0;
        for (int i = 0; i < R; i++) {
            if (mask & (1 << i)) {
                bit_count++;
                for (auto el: red_towers[id_red_towers[i]]) {
                    e.push_back(el);
                }
            }
        }
        sort(e.begin(), e.end());
        dsu DSU(id);
        ll cur = bit_count * 10000;
        for (auto edge: e) {
            if (DSU.comps == 1) break;
            if (DSU.merge(edge.u, edge.v)) {
                cur += edge.cost;
            }
        }
        if (DSU.comps == 1) ans = min(ans, cur);
    }

    cout << ans << endl;
    return 0;
}