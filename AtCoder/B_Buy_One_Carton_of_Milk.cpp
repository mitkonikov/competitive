#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, S, M, L;
    cin >> N >> S >> M >> L;
    ll ans = LLONG_MAX;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                ll eggs = (ll)i * 6 + (ll)j * 8 + (ll)k * 12;
                if (eggs >= N) {
                    ll cost = (ll)i * S + (ll)j * M + (ll)k * L;
                    ans = min(ans, cost);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}