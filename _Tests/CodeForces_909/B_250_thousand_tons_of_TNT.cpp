#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    auto check = [&](int k) {
        vector<ll> sums;
        for (int i = 0; i < N / k; i++) {
            ll s = 0;
            for (int j = 0; j < k; j++) {
                s += A[i * k + j];
            }
            sums.push_back(s);
        }
        sort(sums.begin(), sums.end());
        ans = max(ans, abs(sums.back() - sums.front()));
    };
    for (int k = 1; k * k <= N; k++) {
        if ((N % k) == 0) {
            check(k);
            check(N/k);
        }
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