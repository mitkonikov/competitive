#include <bits/stdc++.h>
#define ll long long

using namespace std;

template<typename I = int>
struct Tree {
    Tree *l = 0, *r = 0;
    I low, high;
    
    // ===============================================================
    ll value = 0;
    ll count = 0;
    
    void update(ll c) {
        count += c;
        value = count * low;
    }
    void merge() {
        value = l->value + r->value;
        count = l->count + r->count;
    }
    // ===============================================================

    Tree(I L, I R) { low = L; high = R; }
    Tree(vector<ll>& v, I L, I R) {
        if (L + 1 == R) {
            value = v[L];
            return;
        }
        
        _push();
        merge();
    }

    ll size() { return high - low; }

    void _push() {
        if (low + 1 == high) {
            return;
        }

        if (!l) {
            I mid = low + (high - low) / 2;
            l = new Tree(low, mid);
            r = new Tree(mid, high);
        }
    }

    void update(I L, I R, ll X) {
        _push();
        if (R <= low || high <= L) return;
        if (L <= low && high <= R) { update(X); return; }
        l->update(L, R, X);
        r->update(L, R, X);
        merge();
    }

    ll query(I K) {
        _push();
        if (low + 1 == high) {
            return low * K;
        }

        if (l->count <= K) {
            return l->value + r->query(K - l->count);
        } else {
            return l->query(K);
        }
        merge();
    }
};

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    Tree<int>* tree = new Tree<int>(0, 1e9 + 10);
    tree->update(0, 1, N);
    vector<int> A(N);
    ll sum = 0;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        tree->update(A[x], A[x] + 1, -1);
        sum -= A[x];
        A[x] = y;
        tree->update(A[x], A[x] + 1, +1);
        sum += A[x];
        cout << sum - tree->query(N - K) << endl;
    }
    return 0;
}