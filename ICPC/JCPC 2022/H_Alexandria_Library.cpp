#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > ng;
vector<vector<int> > bl;
vector<int> d, s;
int cnt = 22;
void build(int ind = 0, int p = -1) {
    if (p == -1) p = ind;
    bl[ind][0] = p;
    for (int i = 1; i < cnt; i++) {
        bl[ind][i] = bl[bl[ind][i - 1]][i - 1];
    }
    s[ind] = 1;
    for (int i = 0; i < ng[ind].size(); i++) {
        int neg = ng[ind][i];
        if (neg == p) continue;
        d[neg] = d[ind] + 1;
        build(neg, ind);
        s[ind] += s[neg];
    }
}
int lift(int ind, int h) {
    for (int i = cnt - 1; i >= 0; i--) {
        int p = bl[ind][i];
        if (d[p] >= h) ind = p;
    }
    return ind;
}
int meet(int a, int b) {
    for (int i = bl[a].size() - 1; i >= 0; i--) {
        int pa = bl[a][i];
        int pb = bl[b][i];
        if (pa != pb) a = pa, b = pb;
    }
    return bl[a][0];
}
int main() {
    ifstream cin("library.in");
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        ng.clear();
        ng.resize(n);
        for (int i = 0, a, b; i < n - 1; i++) {
            cin >> a >> b;
            a--;
            b--;
            ng[a].push_back(b);
            ng[b].push_back(a);
        }
        bl.clear();
        bl.resize(n, vector<int>(cnt));
        d.clear();
        d.resize(n);
        s.clear();
        s.resize(n);
        build();
        for (int i = 0, a, b; i < q; i++) {
            cin >> a >> b;
            a--;
            b--;
            if (a == b) {
                cout << n << endl;
                continue;
            }
            if (d[b] > d[a]) swap(a, b);
            int al = lift(a, d[b]);
            int c = al == b ? b : meet(al, b);
            int llen = d[a] - d[c], rlen = d[b] - d[c];
            int dst = llen + rlen;
            if (dst % 2) {
                cout << 0 << endl;
                continue;
            }
            int m1 = lift(a, d[a] - dst / 2);
            int m2 = lift(a, d[a] - dst / 2 + 1);
            int m3 = lift(b, d[b] - dst / 2 + 1);
            if (llen == rlen) {
                cout << n - s[m2] - s[m3] << endl;
            } else
                cout << s[m1] - s[m2] << endl;
        }
    }
}