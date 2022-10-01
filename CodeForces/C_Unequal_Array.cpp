#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int mn = -1, mx = -1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-1]) {
            if (mn == -1) mn = i;
            mx = i;
        }
    }

    if (mx == mn) cout << 0 << endl;
    else cout << max(1, mx - mn - 1) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}