// A company has n employees with certain salaries.
// Your task is to keep track of the salaries and process queries.
// ! k x : change the salary of employee k to x
// ? a b : count the number of employees whose salary is between a ... b

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Point {
    int x, y;
    bool operator<=(const Point& p) const {
        if (x == p.x) return (y <= p.y);
        return (x <= p.x);
    }
    bool operator<(const Point& p) const {
        if (x == p.x) return (y < p.y);
        return (x < p.x);
    }
    bool operator==(const Point& p) const {
        return (x == p.x && y == p.y);
    }
};

// How many elements are there in the interval [l,r]
template<typename T>
int inRange(Tree<T>& tree, T l, T r) {
    if (tree.empty()) return 0;
    auto il = tree.lower_bound(l);
    auto ir = tree.lower_bound(r);
    if (il == tree.end()) il = prev(tree.end());
    if (ir == tree.end()) ir = prev(tree.end());
    if (ir != tree.begin() && r < ir.m_p_nd->m_value) ir = prev(ir);

    T vl = il.m_p_nd->m_value;
    T vr = ir.m_p_nd->m_value;

    if (vl == vr) return (l <= vl && vl <= r);

    int pl = tree.order_of_key(vl);
    int pr = tree.order_of_key(vr);

    return (pr - pl + 1);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    int id = 1;
    Tree<Point> tree;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        tree.insert({ A[i], id++ });
    }
    for (int i = 0; i < Q; i++) {
        char c;
        cin >> c;
        if (c == '?') {
            int l, r;
            cin >> l >> r;
            cout << inRange<Point>(tree, { l, -1 }, { r, (int)2e9 }) << endl;
        } else if (c == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            auto it = tree.lower_bound({ A[k], 0 });
            tree.erase(it);
            A[k] = x;
            tree.insert({ A[k], id++ });
        }
    }
    return 0;
}