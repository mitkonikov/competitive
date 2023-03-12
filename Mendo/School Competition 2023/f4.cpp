#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
struct SegmentTree {
    vector<int> sgt;
    int cnt;
    int k;
    SegmentTree(int n, int k, int cnt) {
        this->cnt = cnt;
        this->k = k;
        sgt.resize(n, 0);
    }
    void add(int k, int l, int r, int i, int v) {
        if (l == r) {
            sgt[k] += v;
            return;
        }
        int m = (l + r) / 2;
        if (l <= i && i <= m) add(k * 2, l, m, i, v);
        else add(k * 2 + 1, m + 1, r, i, v);
        sgt[k] = sgt[k * 2] + sgt[k * 2 + 1];
    }
    int get(int k, int l, int r, int i) {
        if (l == r) {
            return l;
        }
        if (sgt[k * 2] > i) {
            return get(k * 2, l, (l + r) / 2, i);
        }
        else {
            return get(k * 2 + 1, (l + r) / 2 + 1, r, i - sgt[k * 2]);
        }
    }
    void add(int i, int v) {
        add(1, 0, cnt, i, v);
    }
    int get(int i) {
        assert(sgt[1] == k * k);
        return get(1, 0, cnt, i);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<vector<int>> B(N, vector<int>(N, 0));
    vector<int> comp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            comp.push_back(A[i][j]);
        }
    }
    // index compression
    sort(comp.begin(), comp.end());
    auto getCompressed = [&](int a) {
        return lower_bound(comp.begin(), comp.end(), a) - comp.begin() + 1;
    };
 
    auto uncompress = [&](int a) {
        return comp[a];
    };
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = getCompressed(A[i][j]);
        }
    }
 
    SegmentTree seg(N * N * 21, K, N * N);
    int ans = INT_MAX;
    auto updateAns = [&]() {
        ans = min(ans, comp[seg.get((K * K) / 2)]);
    };
 
    for (int j = 0; j < K; j++) {
        for (int k = 0; k < K; k++) {
            seg.add(B[j][k], 1);
        }
    }
    updateAns();
 
    for (int i = 0; i < N - K + 1; i++) {
        if (i % 2 == 0) {
            // shift to the right
            for (int k = 0; k + K < N; k++) {
                for (int j = 0; j < K; j++) {
                    seg.add(B[i+j][k], -1);
                    seg.add(B[i+j][k+K], 1);
                }
                updateAns();
            }
 
            if (i + K >= N) break;
             
            // shift down at the end
            for (int col = 0; col < K; col++) {
                seg.add(B[i][N-1-col], -1);
                seg.add(B[i+K][N-1-col], 1);
            }
 
            updateAns();
        } else {
            // shift to the left
            for (int k = N - 1; k - K >= 0; k--) {
                for (int j = 0; j < K; j++) {
                    seg.add(B[i+j][k], -1);
                    seg.add(B[i+j][k-K], 1);
                }
                updateAns();
            }
 
            if (i + K >= N) break;
            // shift down at the start
            for (int col = 0; col < K; col++) {
                seg.add(B[i][col], -1);
                seg.add(B[i+K][col], 1);
            }
 
            updateAns();
        }
    }
    cout << ans << endl;
    return 0;
}