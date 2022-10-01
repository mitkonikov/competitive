#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i += 2) {
        ans += a[i] - a[i-1];
    }
    if (n % 2 == 1) {
        cout << "still running" << endl;
    } else {
        cout << ans << endl;
    }
    cout << flush;
    return 0;
}