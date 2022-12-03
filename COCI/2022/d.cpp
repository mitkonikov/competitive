#include <bits/stdc++.h>
#define ll long long

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
    int n, m;
    cin >> n >> m;
    vector<string> leona(n);
    vector<string> zoe(m);
    for (int i = 0; i < n; i++) cin >> leona[i];
    for (int j = 0; j < m; j++) cin >> zoe[j];
    int L = n - 1;
    int R = m - 1;
    SegmentTree ls(n);
    SegmentTree zs(m);
    auto find_range = [&](string& s, vector<string>& look) {
        pair<int, int> res = { -1, -1 };
        auto it = upper_bound(look.begin(), look.end(), s);
        if (it == look.end()) return res;
        if ((*it)[0] >= s[0] + 2) return res;
        res.first = it - look.begin();
        if (s[0] == 'z') {
            res.second = look.size() - 1;
            return res;
        }
        int L = res.first, R = look.size();
        while (R - L > 1) {
            int mid = (R + L) / 2;
            if (look[mid][0] >= s[0] + 2) {
                R = mid;
            } else {
                L = mid;
            }
        }
        res.second = L;
        return res;
    };
    while (!(L == -1 && R == -1)) {
        if (R == -1 || (L != -1 && leona[L] > zoe[R])) {
            auto range = find_range(leona[L], zoe);
            if (range.first != -1) {
                int sum = zs.askLR(range.first, range.second + 1).value;
                if (sum == 0) {
                    ls.put(L, { 1 });
                }
            } else {
                ls.put(L, { 1 });
            }
            L--;
        } else {
            auto range = find_range(zoe[R], leona);
            if (range.first != -1) {
                int sum = ls.askLR(range.first, range.second + 1).value;
                if (sum == 0) {
                    zs.put(R, { 1 });
                }
            } else {
                zs.put(R, { 1 });
            }
            R--;
        }
    }
    int ans = ls.askLR(0, 1).value;
    cout << (ans ? "Leona" : "Zoe") << endl;
    return 0;
}