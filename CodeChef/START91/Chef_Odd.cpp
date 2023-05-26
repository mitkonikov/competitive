#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, K;
    cin >> N >> K;
    if (2LL * K > N) {
        cout << "NO" << endl;
        return;
    }
    if (K == (N + 1) / 2) {
        cout << (N % 2 == 0 ? "YES" : "NO") << endl;
        return;
    }
    if (K < (N + 1) / 2) {
        ll left = N - (K * 2);
        if (((left + 1) / 2) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    cout << "NO" << endl;    
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