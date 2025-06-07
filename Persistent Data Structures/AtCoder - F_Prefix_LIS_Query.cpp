#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct PersistentFenwickTree {
    struct change {
        int data, id;
        change(int d = 0, int i = 0) : data(d), id(i) {}
        inline friend bool operator<(const change &a, const change &b) {
            return a.id < b.id;
        }
    };

    int n, now = 0;
    vector<vector<change>> tree;

    PersistentFenwickTree(int n) {
        tree.resize(n + 100);
        this->n = n;
        for (int i = 0; i <= n; i++) {
            tree[i].push_back(change());
        }
    }

    void modify(int i, int x) {
        for (i++; i <= n; i += i & (-i)) {
            int new_data = max(tree[i].back().data, x);
            tree[i].push_back(change(new_data, now));
        }
        now++;
    }

    int query(int i, int tree_id) {
        int ans = 0;
        vector<change>::iterator a;
        for (i++; i; i -= i & (-i)) {
            a = upper_bound(tree[i].begin(), tree[i].end(),
                            change(0, tree_id)) -
                1;
            ans = max(ans, a->data);
        }
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    map<int, int> comp;
    vector<int> B(A);
    sort(B.begin(), B.end());
    int count = 1;
    for (int i = 0; i < N; i++) {
        auto it = comp.find(B[i]);
        if (it == comp.end()) {
            comp[B[i]] = count;
            count++;
        }
    }

    PersistentFenwickTree pfwt(N + 10);
    for (int i = 0; i < N; i++) {
        int mx = pfwt.query(comp[A[i]] - 1, pfwt.now);
        pfwt.modify(comp[A[i]], mx + 1);
    }

    for (int i = 0; i < Q; i++) {
        int R, X;
        cin >> R >> X;

        int x_comp = prev(comp.upper_bound(X))->second;
        int res = pfwt.query(x_comp, R - 1);
        cout << res << endl;
    }
    return 0;
}