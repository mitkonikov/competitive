#include <bits/stdc++.h>
#include <random>
#include <chrono>
#define ll long long

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto unif = uniform_int_distribution<int>(0, 1000000);

struct Node {
	Node *l = 0, *r = 0;
	// change to ll if necessary
	ll val, y, c = 1; // c - subtree size
	ll rev = 0; // to propagate
	Node(ll val) {
		this->val = val;
		this->y = unif(rng);
	}

	void prop() {
		if (this->rev == 0) return;
        swap(l, r);

		if (l) {
			this->l->rev ^= this->rev;
		}

		if (r) {
			this->r->rev ^= this->rev;
		}

		this->rev = 0;
		recalc();
	}

	void recalc() {
		this->c = 1;

		if (l) {
			this->c += l->c;
		}

		if (r) {
			this->c += r->c;
		}
	}
};

struct Treap {
	ll cnt(Node* n) { return n ? n->c : 0; }
	
	template<class F> void each(Node* n, F f) {
		if (n) { 
			n->prop();
			each(n->l, f);
			f(n->val);
			each(n->r, f);
		}
	}

	pair<Node*, Node*> split(Node* n, ll k) {
		if (!n) return {};
		n->prop();
		if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
			auto pa = split(n->l, k);
			n->l = pa.second;
			n->recalc();
			return {pa.first, n};
		} else {
			auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
			n->r = pa.first;
			n->recalc();
			return {n, pa.second};
		}
	}

	Node* merge(Node* l, Node* r) {
		if (!l) return r;
		if (!r) return l;
		l->prop(); 
		r->prop();
		if (l->y > r->y) {
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		} else {
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	Node* insert(Node* t, Node* n, ll pos) {
		auto pa = split(t, pos);
		return merge(merge(pa.first, n), pa.second);
	}

	// Move the range [l, r) to index k
	void move(Node*& t, ll l, ll r, ll k) {
		Node *a, *b, *c;
		tie(a,b) = split(t, l); tie(b,c) = split(b, r - l);
		if (k <= l) t = merge(insert(a, b, k), c);
		else t = merge(a, insert(c, b, k - r));
	}

	// Reverse the range [l, r)
    void reverse(Node*& t, ll l, ll r) {
		Node *a, *b, *c;
		tie(a, b) = split(t, l); tie(b, c) = split(b, r - l);
		b->rev ^= 1;
        b->prop();
        t = merge(merge(a, b), c);
    }

	Node* createTreap(const vector<ll> &v) {
		assert(!v.empty());
		Node* root = new Node(v[0]);
		for (ll i = 1; i < v.size(); i++) {
			Node* right = new Node(v[i]);
			root = merge(root, right);
		}
		return root;
	}

    vector<ll> toVector(Node* root) {
        vector<ll> result;
        each(root, [&result](ll val) {
            result.push_back(val);
        });
        return result;
    }
};

int main() {
    ll N;
    cin >> N;

    Treap T;
    Node* root = T.createTreap({ 1 });
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        if (i == 0) continue;
        root = T.insert(root, new Node(i + 1), P - 1);
    }

    vector<ll> ans = T.toVector(root);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}