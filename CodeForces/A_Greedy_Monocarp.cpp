#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    int sum = 0;
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum == K) {
            cout << 0 << endl;
            return;
        }
        if (sum > K) break;
        ans = min(ans, K - sum);
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