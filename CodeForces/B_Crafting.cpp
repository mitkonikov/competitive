#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int mn = 1e9 + 100;
    int count = 0;
    int great = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] > A[i]) {
            count++;
            great = B[i] - A[i];
        } else {
            mn = min(mn, (int)(A[i] - B[i]));
        }
    }
    if (count > 1) {
        cout << "NO" << endl;
        return;
    }
    if (count == 0) {
        cout << "YES" << endl;
        return;
    }
    cout << (mn >= great ? "YES" : "NO") << endl;
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