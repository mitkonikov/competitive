#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

// NOTE:
//  1. When merging, don't forget to merge parent[x] instead of parent[u]

template<typename T>
struct RMQ {
	vector<vector<T>> jmp;
    function<T(T, T)> f;
    RMQ() {};
	RMQ(const vector<T>& V, function<T(T, T)> F) : f(F), jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
			jmp.emplace_back(V.size() - pw * 2 + 1);
			for (int j = 0; j < jmp[k].size(); j++)
				jmp[k][j] = f(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return f(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct KRT {
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> cost;
    vector<int> time;
    vector<int> time_out;
    vector<int> reverse_time;
    vector<vector<int>> jump;
    RMQ<int> rmq, rxq;
    int id = 0;
    int timer = 0;
    int LOG = 0;

    KRT(int N) {
        id = N;
        LOG = log2(2 * N - 1) + 2;
        parent.resize(2 * N - 1);
        iota(parent.begin(), parent.end(), 0);
        cost.resize(2 * N - 1);
        adj.resize(2 * N - 1);
        time.resize(2 * N - 1);
        time_out.resize(2 * N - 1);
        reverse_time.resize(2 * N - 1);
        jump.resize(2 * N - 1, vector<int>(LOG));
    }

    int find_set(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }

    bool add_edge(int u, int v, int c) {
        int x = find_set(u);
        int y = find_set(v);
        if (x == y) return false;
        parent[x] = parent[y] = parent[id] = id;
        cost[id] = c;
        adj[id] = { x, y };
        id++;
        return true;
    }

    void euler() {
        int root = id - 1;
        jump[root].resize(LOG, root);
        dfsTimes(root, root);
        rmq = RMQ<int>(time, [&](int a, int b) { return min(a, b); });
        rxq = RMQ<int>(time, [&](int a, int b) { return max(a, b); });
    }

    void dfsTimes(int u, int p) {
        time[u] = timer;
        reverse_time[timer] = u;
        timer++;
        jump[u][0] = p;
        for (int l = 1; l < LOG; l++) {
            jump[u][l] = jump[jump[u][l-1]][l-1];
        }
        for (auto v: adj[u]) {
            dfsTimes(v, u);
        }
        time_out[u] = timer;
    }

    bool is_ancestor(int u, int v) {
        return (time[u] <= time[v] && time_out[v] <= time_out[u]);
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = LOG - 1; i >= 0; --i) {
            if (!is_ancestor(jump[u][i], v))
                u = jump[u][i];
        }
        return jump[u][0];
    }
};

void testCase() {
    int N, M, Q;
    cin >> N >> M >> Q;

    KRT tree(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree.add_edge(u, v, i + 1);
    }

    tree.euler();

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int mn_time = tree.rmq.query(l, r + 1);
        int mx_time = tree.rxq.query(l, r + 1);

        int u = tree.reverse_time[mn_time];
        int v = tree.reverse_time[mx_time];

        int LCA = tree.lca(u, v);
        cout << tree.cost[LCA] << " ";
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