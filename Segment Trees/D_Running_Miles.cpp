#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct SegmentTree {
    const static ll def = -1e10;
    int N = 0;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { max(this->value, other.value) };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) {
        this->N = N;
        seg.resize(4 * N);
    }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = v; return; }
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

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    SegmentTree front(N), back(N);
    for (int i = 2; i < N; i++) {
        back.put(i, { A[i] - i });
    }
    front.put(0, { A[0] });
    ll ans = LLONG_MIN;
    for (int i = 1; i < N - 1; i++) {
        auto b = back.askLR(i + 1, N + 1).value;
        auto f = front.askLR(0, i).value;
        ans = max(ans, f + A[i] + b);

        back.put(i + 1, { (ll)-1e10 });
        front.put(i, { A[i] + i });
    }
    cout << ans << endl;
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