#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct dsu {
    int comps = 0;
    vector<int> parent;

    dsu(int n) {
        comps = n;
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

void testCase() {
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;

    dsu dsu(n);
    int balance = 0;
    vector<int> levels(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (levels[balance] == -1) {
                levels[balance] = i;
            } else {
                dsu.merge(levels[balance], i);
            }
            balance++;
        } else {
            balance--;
            if (levels[balance] != -1) {
                dsu.merge(levels[balance], i);
            }
            for (int b = balance + 1; levels[b] != -1;) {
                levels[b] = -1;
                b++;
            }
        }
    }
    cout << dsu.comps << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}