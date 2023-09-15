#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct SegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        ll left = def;
        ll right = def;
        Node operator+(const Node &other) {
            return { value + other.value, 0, 0 };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(4 * N + 10); }

    void put(int i, int left, int right, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].left += left;
            seg[ind].right += right;
            seg[ind].value = seg[ind].left * seg[ind].right;
            return;
        }
        int m = (l + r) / 2;
        if (i < m) put(i, left, right, ind * 2 + 1, l, m);
        else put(i, left, right, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    SegmentTree tree(N + 10);
    for (int i = 1; i < N; i++) {
        tree.put(A[i], 0, 1);
    }
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        tree.put(A[i], 0, -1);
        tree.put(A[i-1], 1, 0);
        auto res = tree.askLR(0, N + 1);
        auto minus = tree.askLR(A[i], A[i] + 1);
        ans += res.value - minus.value;
    }
    cout << ans << endl;
    return 0;
}