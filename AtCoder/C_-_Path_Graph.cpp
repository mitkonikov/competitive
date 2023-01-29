#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct dsu {
    vector<int> parent;
    int comps = -1;

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
    cin >> N >> M;
    vector<int> deg(N);
    dsu dsu(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        dsu.merge(u, v);
    }
    bool ok = (M == N - 1 && dsu.comps == 1);
    int leafs = 0;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0 || deg[i] > 2) ok = false;
        if (deg[i] == 1) leafs++;
    }
    ok &= (leafs == 2);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}