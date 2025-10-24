#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string T = to_string(N);
    for (int i = 0; i < T.size(); i++) {
        if (T[i] == '7') {
            cout << 0 << endl;
            return;
        }
    }
    if (N % 10 == 8) {
        cout << 1 << endl;
        return;
    }
    int ans = 1e9;
    if (N % 10 == 0) {
        ans = min(ans, 3);
    }
    for (ll i = 9; i <= (ll)N * 100; i = (i * 10) + 9) {
        for (ll k = 1; k <= 10; k++) {
            string T = to_string((ll)N + (ll)k * i);
            for (int j = 0; j < T.size(); j++) {
                if (T[j] == '7') {
                    ans = min(ans, (int)k);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}