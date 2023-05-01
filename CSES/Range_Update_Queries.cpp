#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct LazySegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        ll lazy = def;
        int size = 1;
        
        void push(Node& l, Node& r) {
            (l.size == 1 ? l.value : l.lazy) += lazy;
            (r.size == 1 ? r.value : r.lazy) += lazy;
            lazy = 0;
        }

        Node operator+(const Node &other) {
            return {
                value + other.value + lazy * size + other.lazy * other.size,
                0,
                size + other.size
            };
        }
    };

    vector<Node> seg;
    LazySegmentTree(int N) {
        this->N = N;
        seg.resize(4 * N);
    }

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value = v[l]; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // update [b,e) in node that covers [l,r)
    void update(int b, int e, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return;
        if (l>=b && r<=e) { seg[ind].lazy += v; return; }
        int m = (l + r) / 2;
        seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
        update(b, e, v, ind * 2 + 1, l, m);
        update(b, e, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // result in [b,e) of node that covers [l,r)
    Node query(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
        return query(b, e, ind * 2 + 1, l, m) + query(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    LazySegmentTree tree(N);
    tree.build(A);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            l--; r--;
            tree.update(l, r + 1, u);
        } else {
            int i;
            cin >> i;
            i--;
            cout << tree.query(i, i + 1).value << endl;
        }
    }
    return 0;
}