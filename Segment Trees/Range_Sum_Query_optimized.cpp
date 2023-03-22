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
        ll size = def;
        Data() {}
        Data(int L, int R) { size = R - L; }
        void update(Data x) { value = x.value; }
        static Data merge(Data a, Data b) {
            Data d;
            d.value = a.value + b.value;
            d.size = a.size + b.size;
            return d;
        }
    };
    // ===============================================================

    Data d;

    Tree(I L, I R) {
        low = L;
        high = R;
    }
    ~Tree() {
        if (l) delete l;
        if (r) delete r;
    }
    void update(I P, Data X) {
        if (P + 1 <= low || high <= P) return;
        if (P <= low && high <= P + 1) {
            d.update(X);
            return;
        }
        I mid = low + (high - low) / 2;
        if (P < mid) {
            if (!l) l = new Tree(low, mid);
            l->update(P, X);
        } else {
            if (!r) r = new Tree(mid, high);
            r->update(P, X);
        }
        d = Data::merge((l ? l->d : Data(low, mid)), (r ? r->d : Data(mid, high)));
    }
    Data query(I L, I R) {
        if (R <= low || high <= L) return {};
        if (L <= low && high <= R) return d;
        int mid = low + (high - low) / 2;
        if (l && r) return Data::merge(l->query(L, R), r->query(L, R));
        if (l) return Data::merge(l->query(L, R), Data(mid, high));
        if (r) return Data::merge(Data(low, mid), r->query(L, R));
        return {};
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
            Tree<int>::Data d;
            d.value = B;
            tree->update(A, d);
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