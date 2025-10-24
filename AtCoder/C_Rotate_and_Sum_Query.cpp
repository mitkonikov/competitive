#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(2 * N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) A[N + i] = A[i];
    vector<ll> pref(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        if (i) pref[i] = pref[i-1] + A[i];
        else pref[i] = A[i];
    }
    int offset = 0;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int c;
            cin >> c;
            offset += c;
            offset = offset % N;
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            l += offset;
            r += offset;
            ll ans = pref[r] - (l ? pref[l-1] : 0);
            cout << ans << endl;
        }
    }
    return 0;
}