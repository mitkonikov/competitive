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
    string s;
    cin >> s;
    bool ok = true;
    vector<int> mp(100, -1);
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == -1) {
            mp[a[i]] = s[i];
        } else {
            if (mp[a[i]] != s[i]) {
                ok = false;
            }
        }
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