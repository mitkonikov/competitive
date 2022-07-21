#include <bits/stdc++.h>

using namespace std;

// Verified at https://open.kattis.com/problems/unionfind

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
    int n, q;
    cin >> n >> q;

    dsu ds(n);

    while (q--) {
        char op;
        scanf(" %c", &op);

        int a, b;
        scanf("%d %d", &a, &b);

        if (op == '=') {
            ds.merge(a, b);
        } else {
            cout << (ds.are_same(a, b) ? "yes" : "no") << '\n';
        }
    }
    
    cout << flush;

    return 0;
}