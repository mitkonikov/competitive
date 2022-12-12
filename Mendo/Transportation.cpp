// Task: https://mendo.mk/Task.do?id=713

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
	int val, y, c = 1; // c - subtree size
	int rev = 0; // to propagate
	Node(int val) {
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
	int cnt(Node* n) { return n ? n->c : 0; }
	
	template<class F> void each(Node* n, F f) {
		if (n) { 
			n->prop();
			each(n->l, f);
			f(n->val);
			each(n->r, f);
		}
	}

	pair<Node*, Node*> split(Node* n, int k) {
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

	Node* insert(Node* t, Node* n, int pos) {
		auto pa = split(t, pos);
		return merge(merge(pa.first, n), pa.second);
	}

	// Move the range [l, r) to index k
	void move(Node*& t, int l, int r, int k) {
		Node *a, *b, *c;
		tie(a,b) = split(t, l); tie(b,c) = split(b, r - l);
		if (k <= l) t = merge(insert(a, b, k), c);
		else t = merge(a, insert(c, b, k - r));
	}

	// Reverse the range [l, r)
    void reverse(Node*& t, int l, int r) {
		Node *a, *b, *c;
		tie(a, b) = split(t, l); tie(b, c) = split(b, r - l);
		b->rev ^= 1;
        b->prop();
        t = merge(merge(a, b), c);
    }

	Node* createTreap(const vector<int> &v) {
		assert(!v.empty());
		Node* root = new Node(v[0]);
		for (int i = 1; i < v.size(); i++) {
			Node* right = new Node(v[i]);
			root = merge(root, right);
		}
		return root;
	}
};

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    Treap treap;
    Node* root = treap.createTreap(a);
    int MAGIC = 400;
    vector<int> pointers(MAGIC, -1);
    for (int op = 0; op < N; op++) {
        if (op % MAGIC == 0) {
            pointers.clear();
            pointers.resize(MAGIC);
            // the new pointers should be inside op<=x<op+MAGIC
            int iter = 0;
            treap.each(root, [&](int val){
                if (val >= op && val < op + MAGIC) {
                    pointers[val % MAGIC] = iter;
                }
                iter++;
            });
        }
        int where = pointers[op % MAGIC];
        treap.reverse(root, op, where + 1);
        for (int p = 0; p < pointers.size(); p++) {
            if (pointers[p] == -1) continue;
            if (pointers[p] >= op && pointers[p] <= where) {
                pointers[p] = where - (pointers[p] - op);
            }
        }
        cout << where + 1 << " ";
    }
    cout << endl;
    return 0;
}