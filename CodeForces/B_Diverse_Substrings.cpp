#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> vis(10, 0);
        int dist = 0;
        for (int j = i; j >= max(0, i - 112); j--) {
            if (vis[(s[j] - '0')] == 0) dist++;
            vis[(s[j] - '0')]++;
            bool ok = true;
            for (int k = 0; k < 10 && ok; k++) {
                if (dist < vis[k]) {
                    ok = false;
                }
            }
            if (ok) ans++;
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