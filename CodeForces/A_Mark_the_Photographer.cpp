#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, x;
    cin >> n >> x;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i] + x <= v[i + n]) continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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