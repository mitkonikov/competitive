#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

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
    SegmentTree(int N) { this->N = N; seg.resize(4 * N + 10); }

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


void testCase() {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    vector<int> comp(2 * N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        intervals[i] = { a, b };
        comp[2 * i] = a;
        comp[2 * i + 1] = b;
    }
    sort(comp.begin(), comp.end());
    for (int i = 0; i < N; i++) {
        intervals[i].first = lower_bound(comp.begin(), comp.end(), intervals[i].first) - comp.begin();
        intervals[i].second = lower_bound(comp.begin(), comp.end(), intervals[i].second) - comp.begin();
    }
    SegmentTree tree(2 * N + 10);
    sort(intervals.rbegin(), intervals.rend());
    ll count = 0;
    for (int i = 0; i < N; i++) {
        ll cur = tree.askLR(intervals[i].first, intervals[i].second).value;
        tree.put(intervals[i].second, { 1 });
        count += cur;
    }
    cout << count << endl;
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