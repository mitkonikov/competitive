#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N, K;
    cin >> N >> K;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (K >= N) {
        cout << 1 << endl;
        return 0;
    }
    ll L = -1, R = K - 1;
    ll ans = LLONG_MAX;
    while (R - L > 1) {
        ll M = L + (R - L) / 2;
        ll T = K - M;
        ll all = (K * (K - 1) / 2);
        ll bel = (T * (T - 1) / 2);
        ll top = all - bel;
        ll S = 1 + top;
        if (N - S <= T - 1) {
            ans = min(ans, M + (N - S > 0));
            R = M;
        } else if (S >= N) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    return 0;
}