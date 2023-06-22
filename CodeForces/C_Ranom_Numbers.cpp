#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    ll ans = LLONG_MIN;
    int N = S.size();
    vector<ll> power(5);
    power[0] = 1;
    for (int i = 1; i < 5; i++) power[i] = power[i-1] * 10;
    vector<vector<ll>> st(N, vector<ll>(5, 0));
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        int c = S[i] - 'A';
        if (i) for (int j = 0; j < 5; j++) st[i][j] = st[i-1][j];
        if (i) pref[i] = pref[i-1];
        for (int j = 0; j < c; j++) {
            pref[i] -= st[i][j];
            st[i][j] = 0;
        }
        st[i][c] += power[c];
    }
    int largest = 0;
    ll sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            int c = max(largest, j);
            ll current_sum = sum;
            current_sum += (c < largest ? -1LL : 1LL) * power[c];
            if (i) current_sum += pref[i-1];
            if (i) for (int k = 0; k < 5; k++) {
                current_sum += (k < c ? -1LL : 1LL) * st[i-1][k];
            }
            ans = max(ans, current_sum);
        }
        sum += ((S[i] - 'A') < largest ? -1 : 1) * power[S[i] - 'A'];
        largest = max(largest, S[i] - 'A');
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