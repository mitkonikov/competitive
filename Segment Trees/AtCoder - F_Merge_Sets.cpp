#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct SegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { this->value + other.value };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(4 * N); }

    void put(int i, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value += v; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<int> comp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            comp.push_back(A[i][j]);
        }
    }
    sort(comp.begin(), comp.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = lower_bound(comp.begin(), comp.end(), A[i][j]) - comp.begin() + 1;
        }
    }
    SegmentTree tree(N * M + 10);
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tree.put(A[i][j], 1);
        }
    }
    for (int i = 0; i < N - 1; i++) {
        ll cur_ans = 0;
        for (int j = 0; j < M; j++) {
            cur_ans += tree.askLR(0, A[i][j]).value + (N - i - 1) + (j * (N - i - 1));
        }

        ans += cur_ans;
        for (int j = 0; j < M; j++) {
            tree.put(A[i+1][j], -1);
        }
    }
    cout << ans << endl;
    return 0;
}