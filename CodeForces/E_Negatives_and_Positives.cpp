#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    ll sum = 0;
    vector<ll> A(N);
    int neg = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += abs(A[i]);
        if (A[i] < 0) neg++;
    }
    ll ans = sum;
    ll mn = INT_MAX;
    for (int i = 0; i < N; i++) {
        mn = min(mn, abs(A[i]));
    }
    cout << ans - (neg % 2 == 0 ? 0 : 2LL * mn) << endl;
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