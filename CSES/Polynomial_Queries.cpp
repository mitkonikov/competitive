#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct LazySegmentTree {
    int N = 0;

    struct Node {
        ll value = 0;
        ll size = 1;
        ll s0 = 0;
        ll s1 = 0;

        void push(Node& l, Node& r) {
            l.s0 += s0;
            l.s1 += s1;
            r.s0 += l.size * s1 + s0;
            r.s1 += s1;
            s0 = s1 = 0;
        }

        Node operator+(const Node& r) {
            ll L = value + s0 * size + s1 * (size - 1) * size / 2;
            ll R = r.value + r.s0 * r.size + r.s1 * (r.size - 1) * r.size / 2;

            return {
                L + R,
                size + r.size
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
        if (r - l == 1) {
            seg[ind].value = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // update [b,e) in node that covers [l,r)
    void update(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        
        if (r - l > 1) {
            seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
            seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        }

        if (l >= e || r <= b) return;
        if (l >= b && r <= e) {
            seg[ind].s0 += (1 + l - b);
            seg[ind].s1++;
            return;
        }

        int m = (l + r) / 2;
        update(b, e, ind * 2 + 1, l, m);
        update(b, e, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // result in [b,e) of node that covers [l,r)
    Node query(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l > 1) {
            seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
            seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        }

        if (l >= e || r <= b) return {};
        if (l >= b && r <= e) return seg[ind];
        int m = (l + r) / 2;
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
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            tree.update(l, r + 1);
        } else {
            cout << tree.query(l, r + 1).value << endl;
        }
    }
    return 0;
}