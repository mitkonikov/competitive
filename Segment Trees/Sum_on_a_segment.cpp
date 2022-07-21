#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
    Node *l = nullptr;
    Node *r = nullptr;
    int left;
    int right;
    int nsum;

    Node(int lo, int hi, int val) : left(lo), right(hi), nsum(val) {}

    void add(int pos, int val) {
        nsum += val;
        if (pos < left || pos > right) {
            return;
        }
        if (right - left == 0) {
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            if (l == nullptr) {
                l = new Node(left, mid, 0);
            }
            l->add(pos, val);
        } else {
            if (r == nullptr) {
                r = new Node(mid + 1, right, 0);
            }
            r->add(pos, val);
        }
    }

    int sum(int from, int to) {
        if (to < left || right < from) {
            return 0;
        }
        if (from <= left && right <= to) {
            return nsum;
        }
        return (l ? l->sum(from, to) : 0) + (r ? r->sum(from, to) : 0);
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    Node tree(0, n, 0);

    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;

        if (c == 'A') {
            int i, x;
            cin >> i >> x;
            i--;

            tree.add(i, x);
        } else if (c == 'Q') {
            int l, r;
            cin >> l >> r;
            l--; r--;

            cout << tree.sum(l, r) << endl;
        }
    }

    return 0;
}