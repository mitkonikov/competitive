#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    ll X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    vector<ll> T(A);
    sort(T.begin(), T.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll dw = sum - A[i] - Y;
        ll up = sum - A[i] - X;
        auto uIt = upper_bound(T.begin(), T.end(), up);
        auto dIt = lower_bound(T.begin(), T.end(), dw);
        int ut = (uIt == T.end() ? N : uIt - T.begin());
        int dt = (dIt == T.end() ? N : dIt - T.begin());
        int el = max(ut - dt, 0);
        if (sum - A[i] * 2 >= X && sum - A[i] * 2 <= Y) {
            el--;
        }
        ans += el;
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << endl;
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