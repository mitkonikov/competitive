#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct SegmentTree {
    const static int pw = 1 << 19;
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { this->value + other.value };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) {
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

    void update(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (i < m) update(i, v, ind * 2 + 1, l, m);
        else update(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // result in [b,e) of node that covers [l,r)
    Node query(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return query(b, e, ind * 2 + 1, l, m) + query(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    SegmentTree tree(N);
    tree.build(A);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            tree.update(i, { x });
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << tree.query(l, r + 1).value << endl;
        }
    }
    return 0;
}