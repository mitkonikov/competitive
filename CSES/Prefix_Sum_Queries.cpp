// Given an array of n integers, your task is to process q
// queries of the following types:
//  1. update the value at position k to u
//  2. what is the maximum prefix sum in range [a,b] ?

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct LazySegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        ll lazy = def;
        ll mx_value = LLONG_MIN / 2;
        int size = 1;
        
        void push(Node& l, Node& r) {
            if (l.size == 1) {
                l.value += lazy;
            } else {
                l.lazy += lazy;
            }
            
            if (r.size == 1) {
                r.value += lazy;
            } else {
                r.lazy += lazy;
            }

            l.mx_value += lazy;
            r.mx_value += lazy;
            lazy = 0;
        }

        Node operator+(const Node &other) {
            return {
                value + other.value + lazy * size + other.lazy * other.size,
                0,
                max({ mx_value, other.mx_value }),
                size + other.size
            };
        }
    };

    vector<Node> seg;
    LazySegmentTree(int N) {
        this->N = N;
        seg.resize(4 * N);
    }

    void build(vector<ll>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = { v[l], 0, v[l], 1 }; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // update [b,e) in node that covers [l,r)
    void update(int b, int e, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return;
        if (l>=b && r<=e) { seg[ind].lazy += v; seg[ind].mx_value += v; return; }
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    LazySegmentTree tree(N);
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        if (i) pref[i] = pref[i-1];
        pref[i] += A[i];
    }
    tree.build(pref);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i, x;
            cin >> i >> x;
            i--;
            tree.update(i, N, x - A[i]);
            A[i] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            ll prefL = (l ? tree.query(l-1, l).value : 0);
            cout << max(0LL, tree.query(l, r + 1).mx_value - prefL) << endl;
        }
    }
    return 0;
}