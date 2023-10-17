#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
struct Interval {
    int depth, offset, length;
};
 
inline void eraseOne(multiset<int>& ms, int value) {
    auto it = ms.find(value);
    if (it != ms.end()) ms.erase(it);
}

struct LazySegmentTree {
    int N;
    
    struct Node {
        int value = 0;
        multiset<int> ms;

        void merge_childs(const Node& l, const Node& r) {
            // m < l, r
            // l < m < r
            // r < m < l
            // l, r < m

            if (ms.empty()) {
                value = max(l.value, r.value);
                return;
            }

            auto m = *ms.begin();
            if (m <= min(l.value, r.value)) {
                value = m;
            } else if (l.value <= m && m <= r.value) {
                value = max(m, l.value);
            } else if (r.value <= m && m <= l.value) {
                value = max(m, r.value);
            } else if (max(l.value, r.value) <= m) {
                value = max(l.value, r.value);
            } else {
                assert(false); // shouldn't be any other cases
            }
        }

        void add(int depth) {
            ms.insert(depth);
        }

        void remove(int depth) {
            eraseOne(ms, depth);
        }
    };

    vector<Node> seg;
    LazySegmentTree(int n) {
        N = n;
        seg.resize(4 * N);
    }

    void updateRange(int b, int e, bool add, int depth, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (b>=r || e<=l) return;
        if (b<=l && r<=e) {
            if (add) seg[ind].add(depth);
            else seg[ind].remove(depth);
            // if it's a leaf node, the value is the minimum of the ms.
            if (r - l == 1) seg[ind].value = *seg[ind].ms.begin();
            else seg[ind].merge_childs(seg[2*ind+1], seg[2*ind+2]);
            return;
        }
        int m = (l + r) / 2;
        updateRange(b, e, add, depth, 2 * ind + 1, l, m);
        updateRange(b, e, add, depth, 2 * ind + 2, m, r);
        // here, it's a bit different than usual segment tree
        seg[ind].merge_childs(seg[2*ind+1], seg[2*ind+2]);
    }

    void build(int max_depth, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].ms.insert(max_depth);
            seg[ind].value = *seg[ind].ms.begin();
            return;
        }
        int m = (l + r) / 2;
        build(max_depth, 2 * ind + 1, l, m);
        build(max_depth, 2 * ind + 2, m, r);
        seg[ind].merge_childs(seg[2*ind+1], seg[2*ind+2]);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int Q, H, W;
    cin >> Q >> H >> W;

    int counter = 0;
    vector<Interval> segments(Q);
    
    LazySegmentTree tree(W);
    tree.build(H);

    for (int i = 0; i < Q; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            Interval interval;
            cin >> interval.depth >> interval.offset >> interval.length;
            tree.updateRange(interval.offset, interval.offset + interval.length, 1, interval.depth);
            segments[counter++] = interval;
        } else {
            int id;
            cin >> id;
            id--;
            const auto& interval = segments[id];
            tree.updateRange(interval.offset, interval.offset + interval.length, 0, interval.depth);
        }
        
        cout << tree.seg[0].value << endl;
    }
    return 0;
}