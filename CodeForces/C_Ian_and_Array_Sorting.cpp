#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) sum -= A[i];
        else sum += A[i];
    }
    cout << ((N % 2 == 1 || sum >= 0) ? "YES" : "NO") << endl;
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