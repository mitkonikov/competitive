#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define sz(a) ((a).size())
#define all(a) (a).begin(), (a).end()

using namespace std;

vector<vi> adj;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD()
		: N(sz(adj)), par(N, -1), siz(N, 1), depth(N),
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
    int queryNode(int u) {
        return tree->query(pos[u], pos[u] + 1);
    }
	int queryPath(int u, int v) { // Modify depending on problem
		int res = -1e9;
		process(u, v, [&](int l, int r) {
			res = max(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};

struct BinaryLifting {
    vector<vector<int>> up;
    vector<int> dist;
    int n;

    const int LOG = 19;

    BinaryLifting(int root) {
        this->n = adj.size();
        up.resize(n, vector<int>(LOG + 1));
        dist.resize(n, 0);
        dfs(root, 0);
    }

    void dfs(int v, int p, int d = 0) {
        dist[v] = d;
        up[v][0] = p;
        for (int i = 1; i <= LOG; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (auto u: adj[v]) {
            if (u == p) continue;
            dfs(u, v, d + 1);
        }
    }
};

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    adj.resize(n + 1);
    vector<int> values(n + 1);
    cin >> values[0];
    for (int i = 1; i <= n; i++) {
        int x, p;
        cin >> x >> p;
        values[i] = x;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    HLD<false> hld;
    hld.modifyPath(0, 0, values[0]);
    BinaryLifting BL(0);
    for (int i = 1; i <= n; i++) {
        // binary search over the binary lifting
        int u = i;
        for (int k = BL.LOG; k >= 0; --k) { // O(log(N))
            if (hld.queryNode(BL.up[u][k]) < values[i]) { // O(log(N))
                u = BL.up[u][k];
            }
        }
        cout << BL.dist[i] - BL.dist[u] << '\n';
        hld.modifyPath(u, i, values[i]);
    }
    return 0;
}