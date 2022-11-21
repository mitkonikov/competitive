// Task: https://mendo.mk/Task.do?id=969

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> costs;

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
    int n;
    cin >> n;

    adj.resize(n);
    costs.resize(n, INT_MAX);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> bfs;
    bfs.push(0);
    bfs.push(1);
    costs[0] = costs[1] = 0;
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();

        for (auto v: adj[top]) {
            if (costs[v] > costs[top] + 1) {
                costs[v] = costs[top] + 1;
                bfs.push(v);
            }
        }
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int &a, const int &b) {
        return costs[a] > costs[b]; 
    });

    ll ans = 0;
    dsu dsu(n);
    vector<int> component_sizes(n);
    int comps = 0;
    for (int i = 0; i < n; i++) {
        int u = order[i];

        ll all_sum = dsu.size(u);
        for (auto v: adj[u]) {
            if (costs[v] >= costs[u] && !dsu.are_same(u, v)) {
                component_sizes[comps++] = dsu.size(v);
                all_sum = all_sum + component_sizes[comps - 1];
            }
        }

        for (int k = 0; k < comps; k++) {
            ans = ans + ((ll)component_sizes[k] * (all_sum - component_sizes[k])) * costs[u];
            all_sum -= component_sizes[k];
        }
        
        for (auto v: adj[u]) {
            if (costs[v] >= costs[u]) {
                dsu.merge(u, v);
            }
        }
        
        comps = 0;
    }

    assert(dsu.size(0) == n);

    cout << ans << endl;
    return 0;
}