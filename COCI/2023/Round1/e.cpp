#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

struct dsu_save {
    int u, v, parent_u, parent_v;
};

struct DSU {
    vector<int> parent;
    vector<dsu_save> saves;
    int comps = 0;

    DSU() {};
    DSU(int n) {
        parent.resize(n, -1);
        saves.reserve(n);
        comps = n;
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return find_set(parent[a]);
    }

    bool merge(int a, int b, bool save = false) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return false;
        if (-parent[x] < -parent[y]) swap(x, y);
        if (save) saves.push_back({ x, y, parent[x], parent[y] });
        parent[x] += parent[y];
        parent[y] = x;
        comps--;
        return save;
    }

    void rollback() {
        if (saves.empty()) return;
        dsu_save top = saves.back();
        saves.pop_back();
        parent[top.u] = top.parent_u;
        parent[top.v] = top.parent_v;
        comps++;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

vector<bool> exclude_nodes, is_big;
int ans = 0;
int big_big = 0;

void dfs(int l, int r, int exclude, DSU &dsu) {
    if (l == r) {
        if (l == exclude) return;
        // cout << " ? " << l+1 << " " << exclude_nodes[l] << " " << dsu.comps << endl;
        if (exclude_nodes[l]) {
            if (dsu.comps > 3) {
                ans++;
                if (is_big[l]) big_big++;
            }
        }
        return;
    }
    
    int mid = (l + r) / 2;
    int rollback_count = 0;
    for (int i = l; i <= mid; i++) {
        if (i == exclude) continue;
        for (auto &e: adj[i]) {
            if (e == exclude || (exclude_nodes[e] && (mid + 1 <= e && e <= r))) continue;
            bool saved = dsu.merge(i, e, true);
            rollback_count += saved;
        }
    }
    dfs(mid + 1, r, exclude, dsu);
    for (int i = 0; i < rollback_count; i++) {
        dsu.rollback();
    }

    rollback_count = 0;
    for (int i = mid + 1; i <= r; i++) {
        if (i == exclude) continue;
        for (auto &e: adj[i]) {
            if (e == exclude || (exclude_nodes[e] && (l <= e && e <= mid))) continue;
            bool saved = dsu.merge(i, e, true);
            rollback_count += saved;
        }
    }
    dfs(l, mid, exclude, dsu);
    for (int i = 0; i < rollback_count; i++) {
        dsu.rollback();
    }
}

struct edge {
    int v, u;
    bool united;
    edge() {};
    edge(int _v, int _u) {
        v = min(_v, _u);
        u = max(_v, _u);
    }
};
 
struct QueryTree {
    vector<vector<edge>> t;
    DSU dsu;
    int T;
 
    QueryTree() {}
 
    QueryTree(int _T, int n) : T(_T) {
        dsu = DSU(n);
        t.resize(4 * T + 4);
    }
 
    void add_to_tree(int v, int l, int r, int ul, int ur, edge& q) {
        if (ul > ur)
            return;
        if (l == ul && r == ur) {
            t[v].push_back(q);
            return;
        }
        int mid = (l + r) / 2;
        add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
        add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
    }
 
    void add_query(edge q, int l, int r) {
        add_to_tree(1, 0, T - 1, l, r, q);
    }
 
    void dfs(int v, int l, int r, vector<int>& ans) {
        for (edge& q : t[v]) {
            q.united = dsu.merge(q.v, q.u, true);
        }
        if (l == r)
            ans[l] = dsu.comps;
        else {
            int mid = (l + r) / 2;
            dfs(2 * v, l, mid, ans);
            dfs(2 * v + 1, mid + 1, r, ans);
        }
        for (edge q : t[v]) {
            if (q.united)
                dsu.rollback();
        }
    }
 
    vector<int> solve() {
        vector<int> ans(T);
        dfs(1, 0, T - 1, ans);
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    is_big.resize(N);
    exclude_nodes.resize(N);
    vector<edge> edges(M);
    vector<vector<int>> ve(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = { u, v };
        adj[u].push_back(v);
        adj[v].push_back(u);
        ve[u].push_back(i);
        ve[v].push_back(i);
    }
    vector<pair<int, int>> deg(N);
    for (int i = 0; i < N; i++) {
        deg[i] = { adj[i].size(), i };
    }
    sort(deg.begin(), deg.end());
    const int BIG = 1500;
    vector<int> big;
    for (int i = N - 1, count = 0; i >= 0 && count < BIG; i--, count++) {
        big.push_back(deg[i].second);
        is_big[deg[i].second] = true;
    }
    for (int i = 0; i < big.size(); i++) {
        int u = big[i];
        DSU dsu(N);
        for (auto v: adj[u]) exclude_nodes[v] = true;
        dfs(0, N - 1, u, dsu);
        for (auto v: adj[u]) exclude_nodes[v] = false;
    }
    ans -= big_big / 2;
    // cout << "! ans:" << ans << " big: ";
    // for (auto el: big) cout << el + 1 << " ";
    // cout << endl;
    int SIZE = 0;
    for (auto& [u, v, united]: edges) {
        if (is_big[u] || is_big[v]) continue;
        SIZE++;
    }
    if (SIZE == 0) {
        cout << ans << endl;
        return 0;
    }
    QueryTree qt(3 * SIZE + 10, N);
    vector<int> last_time(M, 0);
    vector<bool> connected(M, true);
    auto disconnect = [&](int u, int time) {
        for (auto edge_id: ve[u]) {
            connected[edge_id] = false;
            if (last_time[edge_id] == time) continue;
            // cout << "edge " << edges[edge_id].u+1 << " " << edges[edge_id].v+1 << " lasts " << last_time[edge_id] << " to " << time << endl;
            qt.add_query(edges[edge_id], last_time[edge_id], time);
            last_time[edge_id] = time;
        }
    };
    auto connect = [&](int u, int time) {
        for (auto edge_id: ve[u]) {
            last_time[edge_id] = time;
            connected[edge_id] = true;
        }
    };
    int time = 1;
    vector<int> query_at;
    query_at.reserve(SIZE);
    for (auto& [u, v, united]: edges) {
        if (is_big[u] || is_big[v]) continue;
        // cout << u+1 << " " << v+1 << endl;
        disconnect(u, time);
        disconnect(v, time);
        time++;
        query_at.push_back(time);
        time++;
        connect(u, time);
        connect(v, time);
        time++;
    }
    for (int i = 0; i < M; i++) {
        if (connected[i]) {
            // cout << "edge " << edges[i].u+1 << " " << edges[i].v+1 << " lasts " << last_time[i] << " to " << time << endl;
            qt.add_query(edges[i], last_time[i], time);
        }
    }
    auto answer = qt.solve();
    // for (auto el: answer) cout << el << " ";
    // cout << endl;
    for (auto time: query_at) {
        int comp = answer[time];
        // cout << "query at " << time << " : " << comp << endl;
        ans += (comp > 3);
    }
    cout << ans << endl;
    return 0;
}