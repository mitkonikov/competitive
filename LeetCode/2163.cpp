#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct SegmentTree {
    const static int pw = 1 << 19;
    int N = pw;

    struct Node {
        int id = 0;
        int count = 0;
        ll sum = 0;
        Node operator+(const Node &other) {
            return {
                0,
                count + other.count,
                sum + other.sum
            };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw); }

    void build(bool rev, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].count = 0;
            seg[ind].sum = 0;
            if (rev) seg[ind].id = N - l - 1;
            else seg[ind].id = l;
            return;
        }
        int m = (l + r) / 2;
        build(rev, ind * 2 + 1, l, m);
        build(rev, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    void inc(int i, int diff, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            seg[ind].count += diff;
            seg[ind].sum += diff * seg[ind].id;
            return;
        }
        int m = (l + r) / 2;
        if (i < m) inc(i, diff, ind * 2 + 1, l, m);
        else inc(i, diff, ind * 2 + 2, m, r);
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

    ll first_k(int k, ll sum, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) {
            return sum + (ll)seg[ind].id * k;
        }
        int m = (l + r) / 2;
        const auto& L = seg[ind * 2 + 1];
        if (k <= L.count) return first_k(k, sum, ind * 2 + 1, l, m);
        return first_k(k - L.count, sum + L.sum, ind * 2 + 2, m, r);
    }
};

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int N = nums.size() / 3;
        const int MX = 1e5 + 10;
        SegmentTree tree(MX);
        tree.build(false);
        vector<ll> front(3 * N), back(3 * N);
        for (int i = 0; i < N; i++) {
            tree.inc(nums[i], 1);
        }
        for (int i = N; i < 3 * N; i++) {
            front[i] = tree.first_k(N, 0);
            tree.inc(nums[i], 1);
        }
        tree.build(true);
        for (int i = 0; i < N; i++) {
            tree.inc(MX - nums[3 * N - i - 1] - 1, 1);
        }
        for (int i = N; i < 3 * N; i++) {
            back[3 * N - i - 1] = tree.first_k(N, 0);
            tree.inc(MX - nums[3 * N - i - 1] - 1, 1);
        }
        ll ans = LLONG_MAX;
        for (int i = N; i <= 2 * N; i++) {
            ans = min(ans, front[i] - back[i-1]);
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    Solution s;
    cout << s.minimumDifference(A) << endl;
}