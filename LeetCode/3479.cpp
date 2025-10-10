#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    const static int pw = 1 << 19;
    const static int def = 0;
    int N = pw;

    struct Node {
        int value = def;
        Node operator+(const Node &other) {
            return { max(this->value, other.value) };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw); }

    void build(vector<int>& vec, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].value = vec[l];
            return;
        }
        int m = (r + l) / 2;
        build(vec, ind * 2 + 1, l, m);
        build(vec, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    bool query(int q, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            if (seg[ind].value >= q) {
                seg[ind].value = 0;
                return true;
            }
            return false;
        }
        int m = (l + r) / 2;
        if (seg[ind * 2 + 1].value >= q) {
            query(q, ind * 2 + 1, l, m);
        } else if (seg[ind * 2 + 2].value >= q) {
            query(q, ind * 2 + 2, m, r);
        } else {
            return false;
        }
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        return true;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int F = fruits.size();
        const int B = baskets.size();
        SegmentTree tree(B);
        tree.build(baskets);
        int ans = 0;
        for (int i = 0; i < F; i++) {
            ans += tree.query(fruits[i]);
        }
        return F - ans;
    }
};