#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) pref[i] = A[i];
        else pref[i] = pref[i-1] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        ll l, r, k;
        cin >> l >> r;
        l--; r--;
        cin >> k;
        ll sum = pref[N-1] - (pref[r] - (l-1 >= 0 ? pref[l-1] : 0)) + (r - l + 1) * k;
        cout << (sum % 2 == 1 ? "YES" : "NO") << endl;
    }
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