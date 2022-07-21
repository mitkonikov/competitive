#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

struct SegmentTree {
    int N;
    struct Node {
        int ones = 0;
        int zeros = 0;
        bool lazy = 0;
        ll inversions1 = 0;
        ll inversions2 = 0;
        Node operator+(const Node &other) const {
            return {
                ones + other.ones,
                zeros + other.zeros,
                0,
                other.inversions1 + inversions1 + (ll)other.zeros * ones,
                other.inversions2 + inversions2 + (ll)other.ones * zeros
            };
        }
    };

    vector<Node> seg;
    SegmentTree(int n) {
        N = n;
        seg.resize(1 << 20);
    }

    void push(int ind, int l, int r) {
        if (seg[ind].lazy == 0) return;
        swap(seg[ind].ones, seg[ind].zeros);
        swap(seg[ind].inversions1, seg[ind].inversions2);
        if (r - l != 1) {
            seg[2*ind+1].lazy ^= seg[ind].lazy;
            seg[2*ind+2].lazy ^= seg[ind].lazy;
        }
        seg[ind].lazy = 0;
    }

    void updateRange(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        push(ind, l, r);
        if (b>=r || e<=l) return;
        if (b<=l && r<=e) {
            seg[ind].lazy ^= 1;
            push(ind, l, r);
            return;
        }
        int m = (l + r) / 2;
        updateRange(b, e, 2 * ind + 1, l, m);
        updateRange(b, e, 2 * ind + 2, m, r);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    Node askRange(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        push(ind, l, r);
        if (e<=l || b>=r) return { 0, 0, 0, 0, 0 };
        if (b<=l && r<=e) return seg[ind];
        int m = (l + r) / 2;
        auto res = askRange(b, e, 2 * ind + 1, l, m) + askRange(b, e, 2 * ind + 2, m, r);
        return res;
    }

    void put(int i, int what, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            if (what) seg[ind].ones = 1;
            else seg[ind].zeros = 1;
            return;
        }
        int m = (l + r) / 2;
        if (i < m) put(i, what, 2 * ind + 1, l, m);
        else put(i, what, 2 * ind + 2, m, r);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    SegmentTree tree(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        tree.put(i, a[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;
        if (type == 1) {
            tree.updateRange(l, r);
        } else {
            cout << tree.askRange(l, r).inversions1 << endl;
        }
    }
    cout << flush;
}