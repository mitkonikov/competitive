#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = LLONG_MAX;
    for (ll a = 1; a <= min(N, (ll)1e6 + 10); a++) {
        ll b = M / a;
        for (ll off = 0; off <= 3; off++) {
            if ((b + off) >= 1 && (b + off) <= N) {
                if (((b + off) * a) >= M) {
                    ans = min(ans, ((b + off) * a));
                }
            }
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}