#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll right_sum = 0;
    ll right = 0;
    ll running_sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        // A[i] . running_sum | right_sum
        // A[i] | running_sum | right_sum
        if (running_sum + A[i] + right > A[i] + running_sum * 2 + right + right_sum) {
            running_sum += A[i];
        } else {
            right_sum += running_sum;
            right += right_sum;
            running_sum = A[i];
        }
    }
    cout << right + right_sum + running_sum << endl;
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