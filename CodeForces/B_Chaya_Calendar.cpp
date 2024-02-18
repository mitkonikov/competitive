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
    ll ans = 0;
    ll year = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > year) {
            year = A[i];
        } else {
            ll take = (year) / A[i] + 1;
            year = A[i] * take;
        }
    }
    cout << year << endl;
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