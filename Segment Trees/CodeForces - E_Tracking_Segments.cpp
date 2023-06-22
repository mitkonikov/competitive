#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct KthMinSegmentTree {
    vector<vector<int>> seg;
    int n;

    KthMinSegmentTree(vector<int> array) {
        this->n = array.size();
        int P = 1;
        while (P <= n) P *= 2;

        pair<int, int> B[P];
        for (int i = 0; i < n; i++) {
            B[i] = { array[i], i };
        }

        for (int i = n; i < P; i++) {
            B[i] = { (int)1e9+10000, -1 };
        }

        this->n = P;
        seg.resize(2 * n);
        sort(B, B + n);
        build(0, 0, n - 1, B);
    }

    void build(int ci, int st, int end, pair<int, int>* B) {
        if (st == end) {
            // Using second property of B
            seg[ci].push_back(B[st].second);
            return;
        }

        int mid = (st + end) / 2;
        build(2 * ci + 1, st, mid, B);
        build(2 * ci + 2, mid + 1, end, B);

        // Inbuilt merge function
        // this takes two sorted arrays and merge
        // them into a sorted array
        merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(),
            seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(),
            back_inserter(seg[ci]));
    }

    // Function to return the index of
    // kth smallest element in range [l, r]
    int query(int ci, int st, int end,
            int l, int r, int k)
    {
        // Base case
        if (st == end)
            return seg[ci][0];

        // Finding value of 'p' as described in article
        // seg[2*ci+1] is left node of seg[ci]
        int p = upper_bound(seg[2 * ci + 1].begin(),
                            seg[2 * ci + 1].end(), r)
                - lower_bound(seg[2 * ci + 1].begin(),
                            seg[2 * ci + 1].end(), l);

        int mid = (st + end) / 2;
        if (p >= k)
            return query(2 * ci + 1, st, mid, l, r, k);
        else
            return query(2 * ci + 2, mid + 1, end, l, r, k - p);
    }
};

struct Interval {
    int l, r;
};

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N, INT_MAX);
    vector<Interval> intervals(M);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        intervals[i] = { l, r };
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int id;
        cin >> id;
        id--;
        A[id] = i;
    }

    KthMinSegmentTree tree(A);
    int ans = INT_MAX;
    for (int i = 0; i < M; i++) {
        auto [l, r] = intervals[i];
        int med = tree.query(0, 0, tree.n - 1, l, r, (r - l + 1) / 2 + 1);
        ans = min(ans, A[med]);
    }
    cout << (ans == INT_MAX ? -1 : ans + 1) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}