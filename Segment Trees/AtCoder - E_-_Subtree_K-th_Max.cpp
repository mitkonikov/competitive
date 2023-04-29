#include <bits/stdc++.h>
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

vector<vector<int>> adj;
vector<int> v;

vector<int> flat;
vector<pair<int, int>> interval;

int timer = 0;

void dfs(int node, int parent) {
    interval[node].first = timer;
    flat[timer++] = v[node];

    for (auto u: adj[node]) {
        if (u == parent) continue;
        dfs(u, node);
    }

    interval[node].second = timer;
}

int main() {
    int n, q;
    cin >> n >> q;

    adj.resize(n);
    v.resize(n);
    flat.resize(n);
    interval.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    if (timer != n) {
        cout << -1 << endl;
        return 0;
    }

    KthMinSegmentTree tree(flat);
    n = tree.n;

    for (int Q = 0; Q < q; Q++) {
        int V, K;
        cin >> V >> K;
        V--;

        int x = interval[V].first;
        int y = interval[V].second - 1;
        int len = y - x + 1;

        // this gets the max
        int q = tree.query(0, 0, n - 1, x, y, len - K + 1);
        cout << flat[q] << "\n";
    }

    cout << flush;
}
