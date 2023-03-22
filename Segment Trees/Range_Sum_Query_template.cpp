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
    const int MOD = 1e9 + 7;
    int N, M;
    cin >> N >> M;
    ll P = 91, Q = 47;
    Tree<int> *tree = new Tree<int>(0, N + 10);
    for (int q = 0; q < M; q++) {
        char type;
        cin >> type;
        if (type == '!') {
            ll A, B;
            cin >> A >> B;
            A = (A + P) % N;
            B = (B + Q) % MOD;
            tree->update(A, { B });
        } else {
            ll A, B;
            cin >> A >> B;
            A = (A + P) % N;
            B = (B + Q) % N;
            if (B < A) swap(A, B);
            ll ans = tree->query(A, B + 1).value;
            P = ((P * 31) % MOD + ans % MOD) % MOD;
            Q = ((Q * 29) % MOD + ans % MOD) % MOD;
            cout << ans << endl;
        }
    }
    return 0;
}