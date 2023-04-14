#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("wigz.in");
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, sw = false, rez = 1e-9, asum = 0;
        cin >> n >> m >> k;
        if (n > m) swap(n, m), sw = true;
        vector<vector<int> > v(n, vector<int>(m));
        for (int i = 0; i < (sw ? m : n); i++)
            for (int j = 0; j < (sw ? n : m); j++) {
                cin >> (sw ? v[j][i] : v[i][j]);
                asum += (sw ? v[j][i] : v[i][j]);
            }
        if (k >= n) {
            cout << asum << endl;
            continue;
        }
        vector<int> sm(1 << n);
        for (int i = 1; i < (1 << n); i++) {
            if (__builtin_popcount(i) == 1)
                for (int j = 0, r = __builtin_ctz(i); j < m; j++)
                    sm[i] += v[r][j];
            else {
                int r = __builtin_ctz(i);
                sm[i] = sm[1 << r] + sm[i - (1 << r)];
            }
        }
        vector<int> s(m), cv(m);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) s[i] += v[j][i];
        for (int bm = 0; bm < (1 << n); bm++) {
            if (__builtin_popcount(bm) > k) continue;
            for (int j = 0, bmc; j < m; j++) {
                cv[j] = s[j], bmc = bm;
                if (bm) do {
                        cv[j] -= v[__builtin_ctz(bmc)][j];
                    } while (bmc -= bmc & -bmc);
            }
            sort(cv.begin(), cv.end());
            reverse(cv.begin(), cv.end());
            int sum = sm[bm];
            for (int l = __builtin_popcount(bm), ll = 0; l < k; l++, ll++) {
                sum += cv[ll];
            }
            rez = max(rez, sum);
        }
        cout << rez << endl;
    }
}