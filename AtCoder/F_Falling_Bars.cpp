#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct Bar {
    int R, C, L, index, ans;

    void read(int i) {
        cin >> R >> C >> L;
        index = i;
    }

    bool operator<(const Bar& other) const {
        return R < other.R;
    }
};

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
    int H, W, N;
    cin >> H >> W >> N;
    vector<Bar> bars(N);
    for (int i = 0; i < N; i++) bars[i].read(i);
    for (int i = 0; i < N; i++) bars[i].R = H - bars[i].R + 1;
    sort(bars.begin(), bars.end());
    LazySegmentTree tree(W + 10);
    for (int i = 0; i < N; i++) {
        int L = bars[i].C;
        int R = bars[i].C + bars[i].L;
        int mx = tree.query(L, R).value;
        bars[i].ans = mx + 1;
        tree.update(L, R, mx + 1);
    }
    for (int i = 0; i < N; i++) bars[i].ans = H - bars[i].ans + 1;
    vector<int> ans(N);
    for (int i = 0; i < N; i++) ans[bars[i].index] = bars[i].ans;
    for (auto& el: ans) cout << el << endl;
    return 0;
}