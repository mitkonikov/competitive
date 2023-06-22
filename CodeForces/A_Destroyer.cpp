#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> frq(110);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }
    bool ok = 1;
    for (int i = 1; i < 110; i++) {
        ok &= (frq[i] <= frq[i-1]);
    }
    cout << (ok ? "YES" : "NO") << endl;
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