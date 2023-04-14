#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("salkan.in");
    int t;
    cin >> t;
    while (t--) {
        int n, lim, rez = 0;
        cin >> n >> lim;
        vector<int> a(n), b(n), f(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) {
            f[i] = (a[i] ^ b[i]);
            rez ^= a[i];
        }
        vector<int> cmb;
        while (true) {
            int pos = 0;
            for (int j = 0; j < n; j++) {
                if (f[j] > f[pos]) pos = j;
            }
            if (f[pos] == 0) break;
            for (int l = 0; l < cmb.size(); l++) {
                if ((cmb[l] ^ f[pos]) < cmb[l]) cmb[l] ^= f[pos];
            }
            cmb.push_back(f[pos]);
            for (int j = 0; j < n; j++) {
                if ((f[j] ^ cmb.back()) < f[j]) f[j] ^= cmb.back();
            }
        }
        int mrez = rez;
        for (int i = 0; i < cmb.size(); i++) {
            if ((mrez ^ cmb[i]) < mrez) mrez ^= cmb[i];
        }
        if (mrez > lim) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < cmb.size(); i++) {
            if ((rez ^ cmb[i]) < rez) {
                int mrez = rez;
                for (int j = i + 1; j < cmb.size(); j++)
                    if ((mrez ^ cmb[j]) < mrez) mrez ^= cmb[j];
                if (mrez > lim) rez ^= cmb[i];
            } else {
                int mrez = rez ^ cmb[i];
                for (int j = i + 1; j < cmb.size(); j++)
                    if ((mrez ^ cmb[j]) < mrez) mrez ^= cmb[j];
                if (mrez <= lim) rez ^= cmb[i];
            }
        }
        cout << rez << endl;
    }
}