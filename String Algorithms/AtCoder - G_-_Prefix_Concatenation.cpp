#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

template<typename T>
inline void umin(T &a, T b) {
    a = min(a, b);
}

struct SegmentTree {
    int N = -1;
    
    struct Node {
        ll value = INT_MAX; // default
        ll lazy = INT_MAX;
        Node operator+(const Node &other) {
            return {
                min(this->value, other.value)
            };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) {
        this->N = N;
        int sz = 1 << 21;
        seg.resize(sz);
    }

    void push(int ind, int l, int r) {
        umin(seg[ind].value, seg[ind].lazy);
        if (r - l != 1) {
            umin(seg[2*ind+1].lazy, seg[ind].lazy);
            umin(seg[2*ind+2].lazy, seg[ind].lazy);
        }
        seg[ind].lazy = INT_MAX;
    }

    void updateRange(int b, int e, int x, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        push(ind, l, r);
        if (e<=l || b>=r) { return; }
        if (b<=l && r<=e) {
            umin(seg[ind].lazy, (ll)x);
            push(ind, l, r);    
            return;
        }

        int m = (l + r) / 2;
        updateRange(b, e, x, 2 * ind + 1, l, m);
        updateRange(b, e, x, 2 * ind + 2, m, r);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        push(ind, l, r);
        if (l>=e || r<=b) return { }; // empty
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    auto v = z_function(s + t);
    
    int n = (int)s.size();
    SegmentTree tree(n + t.size() + 10);
    tree.updateRange(n-1, n, 0);
    for (int i = n - 1; i < n + t.size(); i++) {
        int currentDP = tree.askLR(i, i+1).value;
        if (currentDP == INT_MAX) break;
        tree.updateRange(i+1, i+1+min(v[i+1], n), currentDP + 1);
    }

    int ans = tree.askLR(n + t.size() - 1, n + t.size()).value;
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    cout << flush;
    return 0;
}