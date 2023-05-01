// There are n buildings on a street, numbered 1,2, ... n
// Each building has a pizzeria and an apartment.
// The pizza price in building k is p[k]. 
// If you order a pizza from building a to building b
// its price (with delivery) is p[a]+|a−b|

// Your task is to process two types of queries:
//  1. The pizza price p[k] in building k becomes x.
//  2. You are in building k and want to order a pizza. What is the minimum price?

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct SegmentTree {
    const static ll def = LLONG_MAX / 2;
    int N = 0;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { min(this->value, other.value) };
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
    SegmentTree tree_left(N), tree_right(N);
    for (int i = 0; i < N; i++) {
        tree_left.update(i, { A[i] - i });
        tree_right.update(i, { A[i] + i });
    }
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            tree_left.update(k, { x - k });
            tree_right.update(k, { x + k });
            A[k] = x;
        } else {
            int k;
            cin >> k;
            k--;
            ll l = tree_left.query(0, k + 1).value + k;
            ll r = tree_right.query(k, N).value - k;
            cout << min(l, r) << endl;
        }
    }
    return 0;
}