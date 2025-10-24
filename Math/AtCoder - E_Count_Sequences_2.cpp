#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int maxn = 5010;
int M = 1;
int C[maxn + 1][maxn + 1];

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int pref = 0;
    int sum = accumulate(A.begin(), A.end(), 0);
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * C[sum - pref][A[i]]) % M;
        pref += A[i];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t >> M;

    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = ((ll)C[n - 1][k - 1] + C[n - 1][k]) % M;
    }

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}