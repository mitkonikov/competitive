#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MOD = 1000000007;

struct LazySegmentTree {
    int N;
    
    struct Node {
        vector<int> value = { 0, 0 };
        vector<int> ans = { 0, 0 };
        vector<int> largest = { 0, 0 };
        bool lazy = 0;

        Node operator+(const Node &other) const {
            Node n;
            for (int rep : { 0, 1 }) {
                n.ans[rep] = (largest[rep] == other.largest[rep] ? 
                                ans[rep] : (largest[rep] > other.largest[rep] ? 
                                            ans[rep] : other.ans[rep]));
                n.largest[rep] = max(largest[rep], other.largest[rep]);
            }
            return n;
        }
    };

    vector<Node> seg;
    LazySegmentTree(int n) {
        N = n;
        seg.resize(4 * N);
    }

    void push(int ind, int l, int r) {
        if (seg[ind].lazy == 0) return;
        swap(seg[ind].value[0], seg[ind].value[1]);
        swap(seg[ind].ans[0], seg[ind].ans[1]);
        swap(seg[ind].largest[0], seg[ind].largest[1]);
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

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].value = { v[l], (int)(((ll)v[l] * (MOD - 1)) % MOD) };
            seg[ind].ans = { l, l };
            seg[ind].largest = { v[l], (int)(((ll)v[l] * (MOD - 1)) % MOD) };
            return;
        }
        int m = (l + r) / 2;
        build(v, 2 * ind + 1, l, m);
        build(v, 2 * ind + 2, m, r);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    Node askRange(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        push(ind, l, r);
        if (e<=l || b>=r) return Node();
        if (b<=l && r<=e) return seg[ind];
        int m = (l + r) / 2;
        auto res = askRange(b, e, 2 * ind + 1, l, m) + askRange(b, e, 2 * ind + 2, m, r);
        return res;
    }
};

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    LazySegmentTree tree(N);
    tree.build(A);
    int Q;
    cin >> Q;
    ll sum = 0;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        tree.updateRange(L, R);
        sum += tree.seg[0].ans[0] + 1;
    }
    cout << sum << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}