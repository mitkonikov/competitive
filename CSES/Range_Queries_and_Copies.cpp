#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct PersistantSegTree {
	int N, t = 0;
	struct node {
		node *l = nullptr, *r = nullptr;
		ll x = 0;
	};

	vector<node> vals;
	vector<node*> tree;

	PersistantSegTree(vector<int>& v, int n) {
		this->N = n;
		vals.resize(2 * 200015 * 18);
		tree.resize(200015, nullptr);
		tree[0] = build_tree(v);
	}

	node* build_tree(vector<int>& v, int lo=0, int hi=-1) {
		if (hi == -1) hi = N - 1;
		node* cur = &vals[t++];
		if (lo != hi) {
			int mid = (lo + hi) / 2;
			cur->l = build_tree(v, lo, mid);
			cur->r = build_tree(v, mid + 1, hi);
            cur->x = cur->l->x + cur->r->x;
        } else {
            cur->x = v[lo];
        }
		return cur;
	}

	node* update(node* n, int i, int x, int lo=0, int hi=-1) {
		if (hi == -1) hi = N - 1;
		if (hi < i || lo > i) return n;
		node* v = &vals[t++];
		if (lo == hi) { v->x = x; return v; }
		int mid = (lo + hi) / 2;
		v->l = update(n->l, i, x, lo, mid);
		v->r = update(n->r, i, x, mid + 1, hi);
		v->x = v->l->x + v->r->x;
		return v;
	}

	ll query(node* n, int s, int e, int lo=0, int hi=-1) {
		if (hi == -1) hi = N - 1;
		if (hi < s || lo > e) return 0;
		if (lo >= s && hi <= e) return n->x;
		int mid = (lo + hi) / 2;
		return query(n->l, s, e, lo, mid) + 
				query(n->r, s, e, mid + 1, hi);
	}
};

int main() {
	int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
	PersistantSegTree segtree(A, N);
	vector<int> go(1, 0);
    int sz = 1;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            k--; a--;
            segtree.tree[sz] = segtree.update(segtree.tree[go[k]], a, x);
            go[k] = sz;
            sz++;
        } else if (t == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            k--; a--; b--;
            cout << segtree.query(segtree.tree[go[k]], a, b) << endl;
        } else {
            int k;
            cin >> k;
            k--;
            segtree.tree[sz] = segtree.update(segtree.tree[go[k]], -1, -1);
            go.push_back(sz);
            sz++;
        }
    }
	return 0;
}
