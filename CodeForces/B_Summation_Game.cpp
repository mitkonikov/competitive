#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    ll sum = 0;
    ll ans = LLONG_MIN;
    for (int i = 0; i < N; i++) {
        if (i < X) sum += -A[i];
        else sum += A[i];
    }
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        if (i == 0) pref[i] = A[i];
        else pref[i] = pref[i-1] + A[i];
    }
    ans = max(ans, sum);
    ll new_sum = pref[N-1];
    auto range = [&](int L, int R) {
        ll pL = pref[L];
        ll pR = pref[R];
        return pR - pL;
    };
    for (int i = 0; i < K; i++) {
        new_sum -= A[i];
        ans = max(ans, new_sum - 2LL * (range(i, min(N - 1, i + X))));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}