#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> A[i];
    }
    vector<ll> pref(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        if (i) pref[i] = pref[i-1] + A[i];
        else pref[i] = A[i];
    }
    vector<ll> alt(2 * N);
    for (int i = 1; i < 2 * N; i++) {
        alt[i] = A[i] - A[i-1] + (i - 2 > 0 ? alt[i - 2] : 0LL);
    }
    for (int k = 1; k <= N; k++) {
        ll ans = 0;
        int id = 2 * N - 1 - (k - 2) - 1;
        if (k >= 2) {
            ans -= pref[k-2];
            ans += pref[2 * N - 1] - (id >= 0 ? pref[id] : 0LL);
        }
        ans += alt[id] - (k >= 2 ? alt[k - 2] : 0LL);
        cout << ans << " ";
    }
    cout << endl;
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