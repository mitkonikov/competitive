#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define ll long long
#define all(x) x.begin(), x.end()
 
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
 
int a[810][810];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> h, rh;
    vector<int> comp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            comp.push_back(a[i][j]);
        }
    }
    sort(comp.begin(), comp.end());
    int cnt = 0;
    for (auto x : comp) {
        rh[cnt] = x;
        h[x] = cnt++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = h[a[i][j]]; 
        }
    }
    cnt--;
    comp.clear();
    h.clear();
    SegmentTree sgt(n * n * 20 + 10, k, cnt);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            sgt.add(a[i][j], 1);
        }
    }
    int ind = (k * k) / 2, ans = sgt.get(ind);
    for (int i = 0; i < n - k + 1; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n - k; j++) {
                for (int l = i; l < i + k; l++) {
                    sgt.add(a[l][j], -1);
                    sgt.add(a[l][j + k], 1);
                }
                ans = min(ans, sgt.get(ind));
            }
            if (i + k >= n) break;
            for (int j = n - k; j < n; j++) {
                sgt.add(a[i][j], -1);
                sgt.add(a[i + k][j], 1);
            }
        }
        else {
            for (int j = n - 1; j - k >= 0; j--) {
                for (int l = i; l < i + k; l++) {
                    sgt.add(a[l][j], -1);
                    sgt.add(a[l][j - k], 1);
                }
                ans = min(ans, sgt.get(ind));
            }
            if (i + k >= n) break;
            for (int j = 0; j < k; j++) {
                sgt.add(a[i][j], -1);
                sgt.add(a[i + k][j], 1);
            }
        }
        ans = min(ans, sgt.get(ind));
    }
    ans = min(ans, sgt.get(ind));
    cout << rh[ans];
}