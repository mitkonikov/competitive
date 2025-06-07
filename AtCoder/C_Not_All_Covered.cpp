#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> on(N + 10), off(N + 10);
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        on[L]++;
        off[R+1]++;
    }
    ll cur = 0;
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        cur += on[i] - off[i];
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}