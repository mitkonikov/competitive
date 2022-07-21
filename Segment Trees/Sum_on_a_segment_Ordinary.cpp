#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct SegmentTree {
    const static int pw = 1 << 19;
    const static ll def = 0;
    int N = pw;
    
    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { this->value + other.value };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw); }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
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

int main() {
    int n, k;
    cin >> n >> k;
    SegmentTree tree(n);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;

        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            i--;
            tree.put(i, {x});
        } else if (c == 'Q') {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << tree.askLR(l, r+1).value << endl;
        }
    } return 0;
}