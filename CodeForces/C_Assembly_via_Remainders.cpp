#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> X(N);
    ll mx = 0;
    for (int i = 1; i < N; i++) {
        cin >> X[i];
        mx = max(mx, X[i]);
    }
    vector<ll> ans(N);
    // X[i] = A[i] mod A[i-1]
    // A[i] = A[i-1] * K + X
    ans[0] = mx + 1;
    for (int i = 1; i < N; i++) {
        ans[i] = ans[i-1] + X[i];
    }
    for (auto el: ans) cout << el << " ";
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