#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> depth;
vector<int> color;
vector<int> parent;
vector<int> ans;
map<pair<int, int>, int> edges;

int root = -1;
bool ok = true;

bool isSatisfied(int u) {
    if (adj[u].size() <= 1) return true;
    bool red = false, blue = false;
    for (auto [v, i]: adj[u]) {
        if (ans[i] == 0) red = true;
        else if (ans[i] == 1) blue = true;
    }
    return red && blue;
}

bool dfs(int u, int p, int level = 0) {
    depth[u] = level;
    color[u] = (level % 2 == 0);
    parent[u] = p;
    vector<bool> visited_childs(adj[u].size());
    bool satisfied = false;
    int used = 0;
    for (int k = 0; k < adj[u].size(); k++) {
        auto [v, i] = adj[u][k];
        if (v == p) continue;
        if (depth[v] == -1) {
            // it's not visited
            if (u == root && satisfied) {
                ans[i] = used ^ 1;
                dfs(v, u, level + (used == 0));
            } else {
                ans[i] = (level % 2 == 0);
                bool flip = dfs(v, u, level + 1);
                if (flip) ans[i] ^= 1;
                if (u != root && adj[u].size() == 2) {
                    // I'm a passer
                    return flip;
                }
                used = ans[i];
            }
            visited_childs[k] = true;
            satisfied = true;
        }
    }

    if (u == root) return 0;

    bool meet_root = false;
    bool sat2 = false;
    // Now, we are going to visit back edges
    for (int k = 0; k < adj[u].size(); k++) {
        if (visited_childs[k]) continue;
        auto [v, i] = adj[u][k];
        if (ans[i] != -1) continue;
        if (v == p) continue;
        // now depth is not -1 for sure
        if (satisfied) {
            if (v == root) {
                ans[i] = color[v] ^ 1;
            } else {
                ans[i] = color[v];
            }
        } else {
            if (v == root) {
                meet_root = true;
                continue;
            }
            ans[i] = (level % 2 == 0);
            satisfied = true;
        }
    }

    if (isSatisfied(u)) sat2 = true;

    bool flip = false;
    if (meet_root) {
        for (int k = 0; k < adj[u].size(); k++) {
            auto [v, i] = adj[u][k];
            if (ans[i] != -1) continue;
            if (v != root) continue;
            if (isSatisfied(v)) {
                ans[i] = (level % 2 == 0);
            } else {
                ans[i] = color[v] ^ 1;
                if (!isSatisfied(u)) flip = true;
            }
        }
    }

    return flip;
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    ans.resize(M, -1);
    depth.resize(N, -1);
    parent.resize(N, -1);
    color.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        adj[U].push_back({ V, i });
        adj[V].push_back({ U, i });
        edges[{ U, V }] = i;
        edges[{ V, U }] = i;
    }
    // Visit components which have at least one leaf node
    for (int i = 0; i < N; i++) {
        if (depth[i] != -1) continue;
        if (adj[i].size() == 1) {
            dfs(i, -1);
        }
    }
    // Visit all other components
    for (int i = 0; i < N; i++) {
        if (depth[i] != -1) continue;
        root = i;
        dfs(i, -1);
    }
    for (int i = 0; i < N; i++) {
        if (!isSatisfied(i)) ok = false;
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }
    for (auto el: ans) {
        cout << el + 1;
        assert(el != -1);
    }
    cout << endl;
    return 0;
}