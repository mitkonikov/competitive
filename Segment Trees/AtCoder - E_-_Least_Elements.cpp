#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, madd = 0, val = 0, count = 0;

    void merge() {
        val = l->val + r->val;
        count = l->count + r->count;
    }
    
	void push() {
		if (!l) {
			ll mid = lo + (hi - lo) / 2;
			l = new Node(lo, mid);
            r = new Node(mid, hi);
		}
		if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}

    // Constructors
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large llerval of -inf
	Node(vector<ll>& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
			merge();
		}
		else val = v[lo];
	}

	pair<ll, ll> query(ll L, ll R) {
		if (R <= lo || hi <= L) return { 0, 0 };
		if (L <= lo && hi <= R) return { val, count };
		push();
		pair<ll, ll> resL = l->query(L, R);
        pair<ll, ll> resR = r->query(L, R);
        return { resL.first + resR.first, resL.second + resR.second };
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			madd += x;
			val += x;
            if (x < 0) count--;
            else count++;
		} else {
			push();
            l->add(L, R, x);
            r->add(L, R, x);
			merge();
		}
	}
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    
    const ll MX = 1000010000;
    Node* tree = new Node(0, MX);
    for (int i = 0; i < M; i++) {
        tree->add(a[i], a[i]+1, a[i]);
    }

    auto query = [&]() {
        ll L = 0, R = MX;
        while (R - L > 1) {
            ll MID = (L + R) / 2;
            auto res = tree->query(0, MID);
            if (res.second > K) {
                R = MID;
            } else {
                L = MID;
            }
        }
        auto res1 = tree->query(0, L);
        auto res2 = tree->query(L, L + 1);
        ll left = K - res1.second;
        return res1.first + L * left;
    };

    cout << query() << " ";
    for (int i = M; i < N; i++) {
        tree->add(a[i-M], a[i-M]+1, -a[i-M]);
        tree->add(a[i], a[i]+1, a[i]);
        cout << query() << " ";
    }
    cout << endl;
    return 0;
}