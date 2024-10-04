#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct dsu {
    vector<int> parent;
    int comp = 0;

    dsu(int n) {
        parent.resize(n, -1);
        comp = n;
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
        comp--;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

struct op {
    int d, k;
};

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<vector<op>> ops(N);
    for (int i = 0; i < M; i++) {
        int a, d, k;
        cin >> a >> d >> k;
        a--;
        ops[a].push_back({ d, k });
    }
    dsu DSU(N);
    vector<vector<bool>> visited(N, vector<bool>(14));
    vector<vector<int>> last_processed(N, vector<int>(14));
    for (int i = N - 1; i >= 0; i--) {
        for (auto [d, k]: ops[i]) {
            for (int j = 1; j <= k; j++) {
                int pos = i + d * j;
                if (pos >= N) {
                    break;
                }

                if (visited[pos][d]) {
                    DSU.merge(i, pos);
                    j += (last_processed[pos][d] - pos) / d;
                    last_processed[pos][d] = i + d * k;
                    continue;
                }
                
                DSU.merge(i, pos);
                visited[pos][d] = true;
                last_processed[pos][d] = i + d * k;
            }
        }
    }
    cout << DSU.comp << endl;
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