#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
vector<vector<int>> adj;
vector<int> depthA, depthB;

int far(int u) {
    vector<int> dist(N, INT_MAX);
    dist[u] = 0;
    queue<int> bfs;
    bfs.push(u);
    int last = u;
    while (!bfs.empty()) {
        auto t = bfs.front();
        last = t;
        bfs.pop();
        for (auto v: adj[t]) {
            if (dist[v] > dist[t] + 1) {
                dist[v] = dist[t] + 1;
                bfs.push(v);
            }
        }
    }
    return last;
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

void dfs(int u, int p, int d, vector<int>& depth) {
    depth[u] = d;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1, depth);
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    depthA.resize(N);
    depthB.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int A = far(0);
    int B = far(A);
    dfs(A, -1, 0, depthA);
    dfs(B, -1, 0, depthB);
    dsu DSU(N);
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return max(depthA[a], depthB[a]) > max(depthA[b], depthB[b]);
    });
    vector<int> ans(N, 1);
    int last = 0;
    for (int i = 0; i < N; i++) {
        int u = order[i];
        int d = max(depthA[u], depthB[u]);
        if (depthA[u] > depthB[u]) {
            DSU.merge(u, A);
        } else if (depthA[u] < depthB[u]) {
            DSU.merge(u, B);
        } else {
            DSU.merge(u, A);
            DSU.merge(u, B);
        }
        last = max(last, d - 1);
        ans[d-1] = DSU.comps;
    }
    if (last + 1 < N) ans[last + 1] = N;
    for (int i = 1; i < N; i++) {
        ans[i] = max(ans[i], ans[i-1]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    } cout << endl;
    return 0;
}