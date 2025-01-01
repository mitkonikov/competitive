#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define endl '\n'

using namespace std;

void GospersHack(int n, int k, function<void(lll)> f) {
    lll set = (((lll)1) << k) - 1;
    lll limit = (((lll)1) << n);
    while (set < limit) {
        f(set);
        lll c = set & - set;
        lll r = set + c;
        set = (((r ^ set) >> 2) / c) | r;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll X = 0;
    for (int i = 0; i < N; i++) X ^= A[i];
    bool sw = false;
    if (K >= N / 2 + 1) {
        K = N - K;
        sw = true;
    }
    if (K == 0) {
        cout << X << endl;
        return 0;
    }
    if (K == 1) {
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            mx = max(mx, (sw ? X : 0) ^ A[i]);
        }
        cout << mx << endl;
        return 0;
    }
    if (K == 2) {
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                mx = max(mx, (sw ? X : 0) ^ A[i] ^ A[j]);
            }
        }
        cout << mx << endl;
        return 0;
    }
    if (K == 3) {
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    mx = max(mx, (sw ? X : 0) ^ A[i] ^ A[j] ^ A[k]);
                }
            }
        }
        cout << mx << endl;
        return 0;
    }
    if (K == 4) {
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    for (int l = k + 1; l < N; l++) {
                        mx = max(mx, (sw ? X : 0) ^ A[i] ^ A[j] ^ A[k] ^ A[l]);
                    }
                }
            }
        }
        cout << mx << endl;
        return 0;
    }
    ll ans = 0;
    GospersHack(N, K, [&](lll mask) {
        ll x = 0;
        for (int j = 0; j < N; j++) {
            if ((((lll)1) << j) & mask) {
                x ^= A[j];
            }
        }
        if (sw) x ^= X;
        ans = max(ans, x);
    });
    cout << ans << endl;
    return 0;
}