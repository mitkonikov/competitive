#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
    ~Node() {
        delete l;
        delete r;
    }
	int query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
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

void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Node* tree = new Node(0, N + 1);
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            tree->add(u, v + 1, 1);
        } else {
            int x;
            cin >> x;
            x--;
            int v = tree->query(x, x + 1);
            for (int j = 0; j < v; j++) {
                if (A[x] < 10) break;
                int sum = 0;
                while (A[x] > 0) {
                    sum += A[x] % 10;
                    A[x] /= 10;
                }
                A[x] = sum;
            }
            tree->add(x, x + 1, -v);
            cout << A[x] << endl;
        }
    }
    delete tree;
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