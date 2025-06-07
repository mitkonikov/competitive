#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct LazySegmentTree {
    const static int def = 0;
    int N = 0;

    struct Node {
        int value = def;
        int lazy = def;
        int size = 1;
        
        void push(Node& l, Node& r) {
            l.value = max(l.value, lazy);
            l.lazy = max(l.lazy, lazy);
            r.value = max(r.value, lazy);
            r.lazy = max(r.lazy, lazy);
            value = max(value, lazy);
            lazy = 0;
        }

        Node operator+(const Node &other) {
            return {
                max({ value, other.value, lazy, other.lazy }),
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
        if (l>=b && r<=e) {
            seg[ind].lazy = max(seg[ind].lazy, v);
            seg[ind].value = max(seg[ind].value, v);
            return;
        }
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
    int N, D, DIST;
    cin >> N >> D >> DIST;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> order(N);
    for (int i = 0; i < N; i++) order[A[i] - 1] = i;
    LazySegmentTree tree(N + 10);
    struct update { int L, R, V; };
    vector<update> upd(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int pos = order[i];
        int L = max(0, pos - DIST);
        int R = min(N - 1, pos + DIST);
        tree.update(upd[i].L, upd[i].R + 1, upd[i].V);
        int me = tree.query(pos, pos + 1).value;
        ans = max(ans, me);
        if (i + D < N) {
            upd[i + D] = { L, R, me + 1 };
        }
    }
    cout << ans << endl;
    return 0;
}