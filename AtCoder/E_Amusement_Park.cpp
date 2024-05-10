#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A.push_back(0);
    sort(A.rbegin(), A.rend());
    ll ans = 0;
    auto solve = [&](ll width, ll height, ll dc_offset) {
        ll sum1 = dc_offset * (dc_offset + 1) / 2;
        ll sum2 = (dc_offset + height) * (dc_offset + height + 1) / 2;
        ll sum = sum2 - sum1;
        ll res = sum * width;
        return res;
    };
    for (int i = 0; i < N && K > 0; i++) {
        ll delta = A[i] - A[i+1];
        if (delta == 0) continue;
        ll already = (i + 1);
        ll full = min(delta, K / already);
        ll rem = (full == delta ? 0 : K % already);
        ll inc = solve(already, full, A[i] - full);
        ll inc2 = rem * (A[i] - full);
        ans += inc + inc2;
        K -= full * already + rem;
    }
    cout << ans << endl;
    return 0;
}