#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sum -= A[0];
    ll sum_left = A[0];
    ll ans = A[0];
    for (int i = 1; i < N; i++) {
        ans = gcd(ans, A[i]);
    }
    for (int i = 1; i < N; i++) {
        ans = max(ans, gcd(sum, sum_left));
        sum -= A[i];
        sum_left += A[i];
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