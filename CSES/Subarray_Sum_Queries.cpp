// There is an array consisting of n integers.
// Some values of the array will be updated, and after each update,
// your task is to report the maximum subarray sum in the array.

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct SegmentTree {
    int N = 0;

    struct Node {
        ll value = 0;
        ll max_sub = 0;
        ll pref = 0;
        ll suff = 0;

        void set(ll v) {
            value = v;
            max_sub = v;
            pref = v;
            suff = v;
        }

        Node operator+(const Node &other) {
            Node merge;
            merge.max_sub = max({ max_sub, other.max_sub, suff + other.pref });
            merge.suff = max({ other.suff, suff + other.value });
            merge.pref = max({ pref, value + other.pref });
            merge.value = value + other.value;
            return merge;
        }
    };

    vector<Node> seg;
    SegmentTree(int N) {
        this->N = N;
        seg.resize(4 * N);
    }

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].set(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    void update(int i, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].set(v); return; }
        int m = (l + r) / 2;
        if (i < m) update(i, v, ind * 2 + 1, l, m);
        else update(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    SegmentTree tree(N);
    tree.build(A);
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        tree.update(p, x);
        cout << max(0LL, tree.seg[0].max_sub) << endl;
    }
    return 0;
}