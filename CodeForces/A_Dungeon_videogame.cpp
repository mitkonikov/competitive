#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x >= 0) ans += x;
        else ans--;
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