#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct LazySegmentTree {
    const static ll def = 0;
    #define UNSET LLONG_MIN
    int N = 0;

    struct Node {
        ll value = def;
        ll add = 0;
        ll set = UNSET;
        int size = 1;

        void push_to_value() {
            if (set != UNSET) value = set;
            else if (add) value += add;
            set = UNSET;
            add = 0;
        }

        void Add(ll v) {
            if (size == 1) push_to_value();
            if (set != UNSET) set += v;
            else add += v;
            if (size == 1) push_to_value();
        }

        void Set(ll v) {
            set = v;
            value = v * size;
            add = 0;
        }
        
        void push(Node& l, Node& r) {
            if (add != 0) {
                l.Add(add);
                r.Add(add);
            }
            if (set != UNSET) {
                l.Set(set);
                r.Set(set);
            }

            add = 0;
            set = UNSET;
        }

        Node operator+(const Node &other) {
            ll L = value + add * size;
            if (set != UNSET) L = set * size;
            ll R = other.value + other.add * other.size;
            if (other.set != UNSET) R = other.set * other.size;

            return {
                L + R,
                0,
                UNSET,
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
    void update(int b, int e, int op, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return;
        if (l>=b && r<=e) {
            if (op == 1) { // add
                seg[ind].Add(v);
            } else {
                seg[ind].Set(v);
            }
            return;
        }
        seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
        int m = (l + r) / 2;
        update(b, e, op, v, ind * 2 + 1, l, m);
        update(b, e, op, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    // result in [b,e) of node that covers [l,r)
    Node query(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l > 1) {
            seg[ind].push(seg[ind * 2 + 1], seg[ind * 2 + 2]);
            seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        }
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return query(b, e, ind * 2 + 1, l, m) + query(b, e, ind * 2 + 2, m, r);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> boxes(N);
    for (int i = 0; i < N; i++) cin >> boxes[i];
    LazySegmentTree tree(N);
    tree.build(boxes);
    for (int i = 0; i < M; i++) {
        int X;
        cin >> X;
        auto node = tree.query(X, X + 1);
        ll full = node.value / N;
        ll rem = node.value % N;
        tree.update(X, X + 1, 2, 0);
        tree.update(0, N, 1, full);
        // deal with the remaining
        if (rem <= N - 1 - X) {
            tree.update(X + 1, X + 1 + rem, 1, 1);
        } else {
            tree.update(X + 1, N, 1, 1);
            rem -= N - 1 - X;
            tree.update(0, rem, 1, 1);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << tree.query(i, i + 1).value << " ";
    }
    cout << endl;
    return 0;
}