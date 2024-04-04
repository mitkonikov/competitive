#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> Q(N), A(N), B(N);
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int ans = 0;
    for (ll a = 0; a < (ll)(1e6 + 100); a++) {
        bool failed = false;
        for (int i = 0; i < N; i++) {
            if (a * A[i] > Q[i]) {
                failed = true;
                break;
            }
        }
        if (failed) break;
        int mx = INT_MAX;
        for (int i = 0; i < N; i++) {
            int b_left = Q[i] - a * A[i];
            if (B[i] == 0) continue;
            if (b_left <= 0) mx = 0;
            else mx = min(mx, (int)(b_left / B[i]));
        }
        ans = max(ans, mx + (int)a);
    }
    cout << ans << endl;
    return 0;
}