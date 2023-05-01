#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ll128 __int128_t

using namespace std;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K);
    for (int i = 0; i < K; i++) cin >> A[i];
    ull ans = 0;
    for (int i = 1; i < (1 << K); i++) {
        int bit_count = 0;
        ll128 current = 1;
        for (int bit = 0; bit < K; bit++) {
            if ((1 << bit) & i) {
                current = current * A[bit];
                if (current > N) current = 0;
                bit_count++;
            }
        }

        if (bit_count % 2 == 0) {
            if (current) ans -= N / current;
        } else {
            if (current) ans += N / current;
        }
    }
    cout << ans << endl;
    return 0;
}