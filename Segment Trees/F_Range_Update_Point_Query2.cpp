#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll def = 0;
const ll l_def = -1e18;
template<typename I>
struct Tree {
    Tree *l = 0, *r = 0;
    I low, high;
    
    // ===============================================================
	struct Data {
    	ll lazy = l_def;
		ll value = def;
		ll size = def;
		void update_lazy(ll val) {
			if (lazy == l_def) lazy = val;
			else lazy += val;
		}

		Data() {}
		Data(ll v) { value = v; }
		Data(I L, I R) { size = R - L; }
		void update(Data v) { // update point
			update_lazy(v.value);
		}
		void apply() { // apply lazy
			if (lazy == l_def) return;
			value += lazy;
			lazy = l_def;
		}
		void push(Tree<I> *l, Tree<I> *r) { // push down lazy
			if (lazy == l_def) return;
			l->d.update_lazy(lazy);
			r->d.update_lazy(lazy);
			lazy = l_def;
		}
		static Data merge(Data a, Data b) { // merge two children
			ll children_lazy = (a.lazy == l_def ? 0LL : a.lazy) * a.size;
			children_lazy += (b.lazy == l_def ? 0LL : b.lazy) * b.size;
			Data merged;
			merged.value = a.value + b.value + children_lazy;
			merged.size = a.size + b.size;
			return merged;
		}
	};
    // ===============================================================

    Data d;

    Tree(I L, I R) {
		low = L; high = R;
		d = Data(L, R);
	}
    Tree(vector<Data>& v, I L, I R) {
        if (L + 1 == R) {
            d = v[L];
            return;
        }
        
        _push();
        _merge();
    }

    void _push() {
        if (low + 1 >= high) {
            d.apply();
            return;
        }

        if (!l) {
            I mid = low + (high - low) / 2;
            l = new Tree(low, mid);
            r = new Tree(mid, high);
        }

        d.push(l, r);
    }

	void _merge() {
		if (!l) return;
		d = Data::merge(l->d, r->d);
	}

    void update(I L, I R, Data X) {
        _push();
        if (R <= low || high <= L) return;
        if (L <= low && high <= R) { d.update(X); return; }
        l->update(L, R, X);
        r->update(L, R, X);
        _merge();
    }

    Data query(I L, I R) {
        _push();
        if (R <= low || high <= L) return {};
        if (L <= low && high <= R) return d;
        return Data::merge(l->query(L, R), r->query(L, R));
    }
};


void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Tree<int>* tree = new Tree<int>(0, N + 1);
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            tree->update(u, v + 1, { 1LL });
        } else {
            int x;
            cin >> x;
            x--;
			auto d = tree->query(x, x + 1);
            int v = d.value;
            for (int j = 0; j < v; j++) {
                if (A[x] < 10) break;
                int sum = 0;
                while (A[x] > 0) {
                    sum += A[x] % 10;
                    A[x] /= 10;
                }
                A[x] = sum;
            }
            tree->update(x, x + 1, { -v });
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