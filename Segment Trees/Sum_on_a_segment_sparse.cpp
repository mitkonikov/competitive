#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll def = 0;
template <typename I>
struct Tree {
    Tree *l = 0, *r = 0;
    I low, high;

    // ===============================================================
    struct Data {
        ll value = def;
        void update(Data x) { value = x.value; }
        static Data merge(Data a, Data b) { return {a.value + b.value}; }
    };
    // ===============================================================

    Data d;

    Tree(I L, I R) {
        low = L;
        high = R;
    }
    ~Tree() {
        delete l;
        delete r;
    }
    void _push() {
        if (low + 1 >= high || l) return;
        I mid = low + (high - low) / 2;
        l = new Tree(low, mid);
        r = new Tree(mid, high);
    }
    void _merge() {
        if (!l) return;
        d = Data::merge(l->d, r->d);
    }
    void update(I P, Data X) {
        if (P + 1 <= low || high <= P) return;
        if (P <= low && high <= P + 1) {
            d.update(X);
            return;
        }
        _push();
        l->update(P, X);
        r->update(P, X);
        _merge();
    }
    Data query(I L, I R) {
        if (R <= low || high <= L) return {};
        if (L <= low && high <= R) return d;
        _push();
        return Data::merge(l->query(L, R), r->query(L, R));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    Tree<int> *tree = new Tree<int>(0, 50 * n);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;

        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            i--;
            tree->update(i, {x});
        } else if (c == 'Q') {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << tree->query(l, r + 1).value << endl;
        }
    }
    return 0;
}