#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int MXN = 2 * N + 10;
    vector<int> frq(MXN);
    for (int i = 0; i < N; i++) {
        if (A[i] < MXN) frq[A[i]]++;
    }
    vector<ll> dp(MXN, 1e18);
    for (int i = 0; i < MXN; i++) {
        if (frq[i] == 0) {
            dp[i] = 0;
        }
    }
    for (int j = N + 10; j >= 0; j--) {
        for (int mex = j + 1; mex <= N; mex++) {
            dp[j] = min(dp[j], dp[mex] + j + (ll)max(0, frq[j] - 1) * mex);
        }
    }
    cout << dp[0] << endl;
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