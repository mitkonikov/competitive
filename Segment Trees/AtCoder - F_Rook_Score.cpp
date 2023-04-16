#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct point {
    int r, c, x;
    void read() {
        cin >> r >> c >> x;
    }
};

const ll inf = 1e18 + 1000;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
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
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main() {
    int N;
    cin >> N;
    vector<point> points(N);
    map<int, vector<int>> rows, cols;
    map<int, ll> row_sum;
    Node* segtree = new Node(0, 1e9 + 100);
    for (int i = 0; i < N; i++) {
        points[i].read();
        rows[points[i].r].push_back(i);
        cols[points[i].c].push_back(i);
        row_sum[points[i].r] += points[i].x;
        segtree->add(points[i].c, points[i].c + 1, points[i].x);
    }
    ll ans = 0;
    for (auto it: rows) {
        // deleting the points from DS
        for (auto el: it.second) {
            segtree->add(points[el].c, points[el].c + 1, -points[el].x);
        }

        // get best col
        ll best_col = segtree->query(0, 1e9 + 100);

        for (auto el: it.second) {
            segtree->add(points[el].c, points[el].c + 1, points[el].x);
        }

        ans = max(ans, row_sum[it.first] + best_col);
    }

    cout << ans << endl;
    return 0;
}