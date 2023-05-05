// You are given a list consisting of n integers.
// Your task is to remove elements from the list at given positions, and report the removed elements.

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct SegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        int count = 0;
        Node operator+(const Node &other) {
            return {
                value + other.value,
                count + other.count
            };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) {
        this->N = N;
        seg.resize(4 * N);
    }

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind] = { v[l], 1 }; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    int go(int pos, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind] = { 0, 0 };
            return l;
        }

        int ans;
        int m = (l + r) / 2;
        int left = seg[2 * ind + 1].count;
        if (pos <= left) ans = go(pos, 2 * ind + 1, l, m);
        else ans = go(pos - left, 2 * ind + 2, m, r);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    SegmentTree tree(N);
    tree.build(A);
    for (int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        cout << A[tree.go(pos)] << " ";
    }
    cout << endl;
    return 0;
}