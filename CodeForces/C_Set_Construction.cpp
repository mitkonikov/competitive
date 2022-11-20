#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct TopologicalSort {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> sorted;
    vector<int> in_deg;
    int n;

    TopologicalSort(int n) {
        this->n = n;
        adj.resize(n);
        visited.resize(n, false);
        sorted.reserve(n);
        in_deg.resize(n, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        in_deg[v]++;
    }

    void dfs(int v) {
        visited[v] = true;
        for (auto u: adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }

        sorted.push_back(v);
    }

    void sort() {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i);
        }

        reverse(sorted.begin(), sorted.end());
    }
};

void testCase() {
    int n;
    cin >> n;
    TopologicalSort toposort(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                toposort.addEdge(i, j);
            }
        }
    }
    toposort.sort();
    int count = 0;
    vector<set<int>> ans(n);
    auto extend = [&](set<int> &me, set<int> &other) {
        for (auto el: other) {
            me.insert(el);
        }
    };
    for (int i = 0; i < n; i++) {
        int u = toposort.sorted[i];
        ans[u].insert(count++);
        for (auto v: toposort.adj[u]) {
            extend(ans[v], ans[u]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].size() << " ";
        for (auto el: ans[i]) {
            cout << el + 1 << " ";
        } cout << endl;
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