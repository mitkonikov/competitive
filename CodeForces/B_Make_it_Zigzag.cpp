#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int mx = A[0];
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (i % 2 == 1) {
            mx = max(mx, A[i]);
        } else {
            int cont = max(0, A[i] - (mx - 1));
            mx = max(mx, A[i]);
            ans += cont;
        }
    }
    if (A[0] >= A[1]) ans++;
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