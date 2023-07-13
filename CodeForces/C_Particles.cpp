#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    if (N == 1) {
        cout << A[0] << endl;
        return;
    }
    if (N == 2) {
        cout << max(A[0], A[1]) << endl;
        return;
    }
    ll ans = LLONG_MIN;
    int pos = 0, neg = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, A[i]);
        if (A[i] >= 0) pos++;
        else neg++;
    }
    if (neg == N || pos == 1) {
        cout << ans << endl;
        return;
    }
    // two positives
    while (A.back() < 0) A.pop_back();
    bool ok = 0;
    vector<int> B;
    B.reserve(N);
    for (int i = 0; i < A.size(); i++) {
        if (ok) {
            B.push_back(A[i]);
            continue;
        }
        
        if (A[i] >= 0) {
            ok = 1;
            B.push_back(A[i]);
        }
    }
    N = B.size();
    vector<vector<int>> P(2, vector<int>());
    for (int i = 0; i < N; i++) {
        P[i%2].push_back(B[i]);
    }
    for (int r = 0; r < 2; r++) {
        ll sum = 0;
        while (!P[r].empty() && P[r].back() < 0) P[r].pop_back();
        for (int i = 0; i < P[r].size(); i++) sum += max(P[r][i], 0);
        ans = max(ans, sum);
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