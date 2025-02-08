#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

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
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
    }
    dsu DSU(N);
    vector<array<int, 3>> possible_reconnects;
    for (int i = 0; i < M; i++) {
        auto [u, v] = edges[i];
        if (!DSU.are_same(u, v)) {
            DSU.merge(u, v);
        } else {
            possible_reconnects.push_back({
                i, u, v
            });
        }
    }
    int K = DSU.comps - 1;
    cout << K << endl;
    set<int> roots;
    for (int i = 0; i < N; i++) {
        if (DSU.parent[i] < 0) {
            roots.insert(i);
        }
    }
    int count = 0;
    for (int i = 0; i < possible_reconnects.size(); i++) {
        if (count == K) break;
        auto [idx, u, v] = possible_reconnects[i];
        for (auto r : roots) {
            if (!DSU.are_same(v, r)) {
                cout << idx + 1 << " " << v + 1 << " " << r + 1 << endl;
                roots.erase(r);
                DSU.merge(v, r);
                count++;
                break;
            }
        }
    }
    assert(count == K);
    return 0;
}