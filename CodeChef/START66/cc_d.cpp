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

void testCase() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    dsu dsu(n);
    ll ans = 0;
    for (int bit = 0; bit < 30; bit++) {
        if (dsu.comps == 1) break;
        sort(a.rbegin(), a.rend(), [&](const auto& a, const auto& b) {
            return ((a.first & (1 << bit)) < (b.first & (1 << bit)));
        });
        int p1 = 0;
        int p2 = 1;
        while (p1 < a.size() && p2 < a.size()) {
            if (((a[p1].first & (1 << bit)) == (a[p2].first & (1 << bit))) && (a[p1].first & (1 << bit)) > 0) {
                int u = a[p1].second;
                int v = a[p2].second;
                if (!dsu.are_same(u, v)) {
                    dsu.merge(u, v);
                    ans += (1LL << bit);
                }
            }

            p2++;
        }
    }

    if (dsu.comps == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
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