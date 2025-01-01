#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline int to_int(const vector<int>& c, const vector<int>& d) {
    int result = 0;
    int dim = 1;
    for (int i = c.size() - 1; i >= 0; i--) {
        result += c[i] * dim;
        dim *= d[i];
    }
    return result;
}

inline void from_int(int a, vector<int>& c, const vector<int>& d) {
    int dim = 1;
    for (int i = 1; i < d.size(); i++) dim *= d[i];
    for (int i = 0; i < c.size(); i++) {
        c[i] = a / dim;
        a %= dim;
        if (i+1 < d.size()) dim /= d[i+1];
    }
}

inline void read(vector<int>& L) {
    for (int i = 0; i < L.size(); i++) {
        cin >> L[i];
        L[i]--;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int D;
    cin >> D;
    vector<int> d(D);
    int MX = 1;
    for (int i = 0; i < D; i++) {
        cin >> d[i];
        MX *= d[i];
    }
    vector<int> A(MX);
    for (int i = 0; i < MX; i++) cin >> A[i];
    vector<int> pref(A);
    for (int i = 0; i < MX; i++) {
        vector<int> c(D);
        from_int(i, c, d);
        for (int mask = 1; mask < (1 << D); mask++) {
            int bit_count = 0;
            vector<int> new_c(c);
            bool neg = false;
            for (int j = 0; j < D && !neg; j++) {
                if ((1 << j) & mask) {
                    bit_count++;
                    new_c[j]--;
                    neg |= (new_c[j] < 0);
                }
            }
            if (!neg) {
                if (bit_count % 2 == 0) {
                    pref[i] -= pref[to_int(new_c, d)];
                } else {
                    pref[i] += pref[to_int(new_c, d)];
                }
            }
        }
    }
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        vector<int> L(D), R(D);
        read(L);
        read(R);
        int ans = 0;
        for (int mask = 0; mask < (1 << D); mask++) {
            int bit_count = 0;
            vector<int> c(D);
            bool neg = false;
            for (int j = 0; j < D && !neg; j++) {
                if ((1 << j) & mask) {
                    bit_count++;
                    c[j] = L[j] - 1;
                } else {
                    c[j] = R[j];
                }

                if (c[j] < 0) neg = true;
            }
            if (!neg) {
                if (bit_count % 2 == 0) {
                    ans += pref[to_int(c, d)];
                } else {
                    ans -= pref[to_int(c, d)];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}