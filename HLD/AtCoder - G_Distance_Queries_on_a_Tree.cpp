#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define vi vector<int>
#define vll vector<ll>
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

using namespace std;

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
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
	void modifyPath(int u, int v, ll val) {
		process(u, v, [&](int l, int r) {
            tree->set(l, r, val);
        });
	}
	ll queryPath(int u, int v) { // Modify depending on problem
		ll res = 0;
		process(u, v, [&](int l, int r) {
			res = res + tree->query(l, r);
		});
		return res;
	}
};

struct edge {
    int u, v, w;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<edge> edges(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = { u, v, w };
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD<true> hld(adj);
    for (int i = 0; i < N - 1; i++) {
        hld.modifyPath(edges[i].u, edges[i].v, edges[i].w);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, w;
            cin >> i >> w;
            i--;
            hld.modifyPath(edges[i].u, edges[i].v, w);
        } else {
            int u, v;
            cin >> u >> v;
            u--; v--;
            cout << hld.queryPath(u, v) << endl;
        }
    }
    return 0;
}