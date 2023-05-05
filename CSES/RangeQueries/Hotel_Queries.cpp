// There are n hotels on a street. For each hotel you know the number of free rooms.
// Your task is to assign hotel rooms for groups of tourists.
// All members of a group want to stay in the same hotel.

// The groups will come to you one after another, and you know for each group the number of rooms it requires.
// You always assign a group to the first hotel having enough rooms.
// After this, the number of free rooms in the hotel decreases.

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct SegmentTree {
    const static ll def = 0;
    int N = 0;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { max(value, other.value) };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(4 * N); }

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value = v[l]; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    int go(int req, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            if (seg[ind].value >= req) {
                seg[ind].value -= req;
                return l;
            } else {
                return -1;
            }
        }

        int m = (l + r) / 2;
        int ans = 0;
        if (seg[2 * ind + 1].value >= req) ans = go(req, 2 * ind + 1, l, m);
        else ans = go(req, 2 * ind + 2, m, r);

        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
        return ans;
    }
};

int main() {
    int H, G;
    cin >> H >> G;
    vector<int> hotels(H), groups(G);
    for (int i = 0; i < H; i++) cin >> hotels[i];
    for (int i = 0; i < G; i++) cin >> groups[i];

    SegmentTree tree(H);
    tree.build(hotels);

    for (int i = 0; i < G; i++) {
        cout << tree.go(groups[i]) + 1 << " ";
    }
    cout << endl;

    return 0;
}