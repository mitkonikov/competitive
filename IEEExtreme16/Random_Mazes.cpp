#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct dsu {
    vector<int> parent;
    vector<bool> cycle;

    dsu(int n) {
        parent.resize(n, -1);
        cycle.resize(n, false);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    bool is_cycle(int a) {
        int x = find_set(a);
        return cycle[x];
    }

    int merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) {
            cycle[x] = true;
            return x;
        }
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        if (cycle[y]) cycle[x] = true;
        if (cycle[x]) cycle[y] = true;
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

    dsu dsu(n * n);

    int child = 0;
    int monster = n - 1;
    int toy = (n - 1) * n + n - 1;

    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;

        int node = u * n + v;
        
        int dx = 0, dy = 0;
        if (c == 'N') {
            dx--;
        } else if (c == 'S') {
            dx++;
        } else if (c == 'W') {
            dy--;
        } else {
            dy++;
        }

        int new_node = (u + dx) * n + (v + dy);

        if (dsu.find_set(node) == dsu.find_set(child)) {
            if (dsu.find_set(new_node) == dsu.find_set(monster)) {
                cout << "M" << endl;
                continue;
            }
        }
        
        if (dsu.find_set(new_node) == dsu.find_set(child)) {
            if (dsu.find_set(node) == dsu.find_set(monster)) {
                cout << "M" << endl;
                continue;
            }
        }

        if (dsu.find_set(node) == dsu.find_set(child) 
        && (dsu.find_set(new_node) == dsu.find_set(child) || dsu.is_cycle(new_node))) {
            cout << "L" << endl;
            continue;
        }

        if (dsu.find_set(new_node) == dsu.find_set(child) 
        && (dsu.find_set(node) == dsu.find_set(child) || dsu.is_cycle(node))) {
            cout << "L" << endl;
            continue;
        }

        auto f = [&]() {
            if (dsu.find_set(node) == dsu.find_set(child)) {
                if (dsu.find_set(new_node) == dsu.find_set(monster)) {
                    cout << "M" << endl;
                } else if (dsu.find_set(new_node) == dsu.find_set(child) || dsu.is_cycle(new_node)) {
                    cout << "L" << endl;
                } else if (dsu.find_set(new_node) == dsu.find_set(toy) || dsu.find_set(child) == dsu.find_set(toy)) {
                    cout << "T" << endl;
                    dsu.merge(node, new_node);
                } else {
                    cout << "K" << endl;
                    dsu.merge(node, new_node);
                }
                return true;
            }
            return false;
        };

        if (!f()) {
            swap(node, new_node);

            if (!f()) {
                if (dsu.find_set(node) == dsu.find_set(toy) && dsu.find_set(toy) == dsu.find_set(child)) {
                    cout << "T" << endl;
                } else {
                    cout << "K" << endl;
                }

                dsu.merge(node, new_node);
            }
        }
    }

    cout << endl;
    return 0;
}