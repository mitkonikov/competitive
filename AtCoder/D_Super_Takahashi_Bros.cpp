#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    const ll INF = 1e18 + 10;
    vector<ll> dp(N, INF);
    vector<ll> A(N), B(N), X(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i] >> X[i];
        X[i]--;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dp[0] = 0;
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        auto [cost, me] = pq.top();
        pq.pop();
        if (me == N - 1) continue;
        if (dp[me + 1] > dp[me] + A[me]) {
            dp[me + 1] = dp[me] + A[me];
            pq.push({ dp[me + 1], me + 1 });
        }
        if (dp[X[me]] > dp[me] + B[me]) {
            dp[X[me]] = dp[me] + B[me];
            pq.push({ dp[X[me]], X[me] });
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}