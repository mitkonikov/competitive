#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sz = (n / 2 + (n % 2));
    vector<vector<int>> mp(2, vector<int>(sz));
    for (int i = 0; i < sz; i++) {
        mp[0][i] = a[i];
        mp[1][i] = a[n-i-1];
    }
    for (int i = 0; i < sz; i++) {
        if (mp[0][i] == mp[1][i]) {
            mp[0][i] = 0;
            mp[1][i] = 0;
            continue;
        }

        if (mp[0][i] < mp[1][i]) {
            mp[0][i] = (mp[1][i] - mp[0][i]);
            mp[1][i] = 0;
        } else {
            mp[1][i] = (mp[0][i] - mp[1][i]);
            mp[0][i] = 0;
        }
    }
    ll ans = 0;
    for (int k = 0; k < 2; k++) {
        ll mn = mp[k][0];
        for (int i = 1; i < sz; i++) {
            if (mp[k][i] == mn) {
                continue;
            } else if (mp[k][i] < mn) {
                ans += (mn - mp[k][i]);
                mn = mp[k][i];
            } else {
                mn = mp[k][i];
            }
        }
        ans += mn;
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