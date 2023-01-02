#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int inf = 1e9;

struct SegmentTree {
    const static int pw = 1 << 16;
    const static int def = inf;
    int N = pw;

    struct Node {
        int value = def;
        Node operator+(const Node &other) {
            return { min(this->value, other.value) };
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
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    int MX = 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        MX = max(MX, a[i]);
    }
    MX++;
    vector<vector<SegmentTree>> trees(2, vector<SegmentTree>(K + 1, SegmentTree(MX)));
    int global_ans = inf;
    for (int i = 0; i < N; i++) {
        for (int k = min(i + 1, K); k >= 2; k--) {
            int ans = inf;
            
            // get from the previous tree, minimum from the left side
            int q1 = trees[0][k-1].askLR(0, a[i] + 1).value;
            if (q1 != inf) {
                int shift_back = MX - 1 - a[i];
                ans = min(ans, q1 - shift_back);
            }

            // get from the previous tree, minimum from the right side
            int q2 = trees[1][k-1].askLR(a[i], MX + 10).value;
            if (q2 != inf) {
                int shift_back = a[i];
                ans = min(ans, q2 - shift_back);
            }

            if (ans == inf) continue;

            if (k == K) global_ans = min(global_ans, ans);
            trees[0][k].put(a[i], { ans + MX - 1 - a[i] });
            trees[1][k].put(a[i], { ans + a[i] });
        }

        // add this to tree K = 1
        trees[0][1].put(a[i], { MX - 1 - a[i] });
        trees[1][1].put(a[i], { a[i] });
    }
    cout << global_ans << endl;
    return 0;
}