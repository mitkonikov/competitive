#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    ll all = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        all += A[i];
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    vector<ll> pref(N), suff(N + 1);
    for (int i = 0; i < N; i++) {
        if (i) pref[i] = pref[i-1] + A[i];
        else pref[i] = A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        suff[i] = suff[i+1] + A[i];
    }
    for (int mn = 0; mn <= K; mn++) {
        ll p = ((2*mn-1>0) ? pref[2 * mn - 1] : 0);
        ll s = (suff[N - (K - mn)]);
        ans = max(ans, all - p - s);
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