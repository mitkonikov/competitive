#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

const int INF = 1e9;

inline void umin(int& a, int b) {
    if (b < a) a = b;
}

struct Data {
    int parent, val;
};

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, val = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	int query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            umin(val, x);
            umin(mset, x);
        }
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
	}
};

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	void process(int u, int v, function<void(int, int)> op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) {
            tree->set(l, r, val);
        });
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = inf;
		process(u, v, [&](int l, int r) {
			res = min(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};

vector<vector<int>> adj;
vector<int> dp;

int dfs(int u, int p) {
    dp[u] = u;
    for (auto v: adj[u]) {
        if (v == p) continue;
        umin(dp[u], dfs(v, u));
    }
    return dp[u];
}

int find_set(int u, HLD<false>& hld) {
    int leader = hld.queryPath(u, u);
    if (leader == u) return u;
    int new_leader = find_set(leader, hld);
    hld.modifyPath(u, u, new_leader);
    return new_leader;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    adj.resize(N);
    dp.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i + 1);
        adj[i + 1].push_back(p);
    }
    dfs(0, -1);
    HLD<false> tree(adj);
    for (int i = 0; i < N; i++) tree.modifyPath(i, i, i);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            tree.modifyPath(u, v, v);
        } else {
            int u;
            cin >> u;
            u--;
            int root = find_set(u, tree);
            cout << dp[root] + 1 << endl;
        }
    }
    return 0;
}