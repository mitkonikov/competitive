#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct SegmentTree {
    const static int pw = 1 << 19;
    const static ll def = (1 << 30) - 1;
    int N = pw;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { this->value & other.value };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(4 * N); }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    
    void build(vector<int>& A, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value = A[l]; return; }
        int m = (l + r) / 2;
        build(A, ind * 2 + 1, l, m);
        build(A, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    Node ask(int i, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (i + 1 >= r) return seg[ind];
        if (i < l) return { };
        int m = (l + r) / 2;
        return ask(i, ind * 2 + 1, l, m) + ask(i, ind * 2 + 2, m, r);
    }
    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
    }
};


void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;
    SegmentTree tree(N);
    tree.build(A);
    for (int i = 0; i < Q; i++) {
        int L, K;
        cin >> L >> K;
        L--;
        if (A[L] < K) {
            cout << -1 << " ";
            continue;
        }
        int BL = L, BR = N + 1;
        while (BR - BL > 1) {
            int MID = (BR + BL) / 2;
            int q = tree.askLR(L, MID).value;
            if (q < K) {
                BR = MID;
            } else {
                BL = MID;
            }
        }
        // BL is ok
        cout << BL << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}