#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> frq;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += frq[A[i]];
        if (A[i] == 2) ans += frq[1];
        if (A[i] == 1) ans += frq[2];
        frq[A[i]]++;
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