#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < Q; i++) {
        vector<ll> A(T);
        ll K;
        cin >> K;
        ll ans = 0;
        for (int b = 60; b >= 0; b--) {
            vector<bool> flipped(N);
            ll current_cost = 0;
            for (int j = 0; j < N; j++) {
                const ll flip = (1LL << b);
                if (A[j] & flip) continue;
                const ll mask = (A[j] & ((1LL << b) - 1));
                ll cost = (1LL << b) - mask;
                flipped[j] = true;
                current_cost += cost;
                if (current_cost > K) break;
            }
            if (current_cost <= K) {
                // everything else goes to zero
                for (int j = 0; j < N; j++) if (flipped[j]) A[j] = 0;
                ans += (1LL << b);
                K -= current_cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}