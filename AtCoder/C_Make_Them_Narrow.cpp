#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll ans = LLONG_MAX;
    K = N - K;
    for (int i = 0; i < N - K + 1; i++) {
        ans = min(ans, (ll)A[i + K - 1] - A[i]);
    }
    cout << ans << endl;
    return 0;
}