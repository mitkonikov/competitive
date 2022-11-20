#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct BridgeFinder {
    // adj[u] = adjacent nodes of u
    // ap = articulation points (output)
    // p = parent
    // disc[u] = discovery time of u
    // low[u] = 'low' node of u
    vector<vector<int>> adj;
    vector<int> disc;
    vector<int> low;
    vector<int> ap;

    int timer = 0;

    BridgeFinder(int n) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int u, int p) {
        int children = 0;
        low[u] = disc[u] = ++timer;
        for (int& v : adj[u]) {
            // we don't want to go back through the same path.
            // if we go back is because we found another way back
            if (v == p) continue;
            if (!disc[v]) { // if V has not been discovered before
            children++;
            dfs(v, u);
            if (disc[u] <= low[v])
                ap[u] = 1;
            low[u] = min(low[u], low[v]);
            // low[v] might be an ancestor of u
            } else
            // if v was already discovered means
            // that we found an ancestor
            // => finds the ancestor with the least discovery time
            low[u] = min(low[u], disc[v]);
        }
        return children;
    }

    void solve() {
        ap = low = disc = vector<int>(adj.size());
        for (int u = 0; u < adj.size(); u++)
            if (!disc[u])
                ap[u] = dfs(u, u) > 1;
    }
};

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
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    // 1. Check if there's only one component 
    // 2. Check if we can do it in one flip
    // 3. Check comps > 2:
    //     - print(leaders)
    // 4. If comps == 2:
    //      size(u) < size(v)
    dsu dsu(n);
    BridgeFinder BF(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][j] == '1') {
                dsu.merge(i, j);
                BF.add_edge(i, j);
            }
        }
    }
    BF.solve();
    if (dsu.comps == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dsu.are_same(i, j) && mat[i][j] == '0' && !BF.ap[i]) {
                // i can do it in one flip;
                cout << 1 << endl << i + 1 << endl;
                return;
            }
        }
    }
    set<int> leaders;
    for (int i = 0; i < n; i++) {
        leaders.insert(dsu.find_set(i));
        if (dsu.size(i) == 1) {
            cout << 1 << endl << i + 1 << endl;
            return;
        }
    }
    vector<int> l;
    l.reserve((int)leaders.size());
    for (auto el: leaders) {
        l.push_back(el);
    }
    if (leaders.size() > 2) {
        // 2 flips
        cout << 2 << endl;
        cout << l[0] + 1 << " " << l[1] + 1 << endl;
        return;
    }
    int l1 = l[0];
    int l2 = l[1];
    if (dsu.size(l2) < dsu.size(l1)) {
        swap(l1, l2);
    }
    cout << dsu.size(l1) << endl;
    for (int i = 0; i < n; i++) {
        if (dsu.are_same(l1, i)) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}