#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, liters, k;
    cin >> n >> liters >> k;
    vector<int> a(n);
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) pref[i] = (a[i] >= liters);
        else pref[i] = pref[i-1] + (a[i] >= liters);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll last = (i + k < n ? pref[i+k] : pref[n-1]);
        ll first = (i - 1 >= 0 ? pref[i-1] : 0);
        if (last - first == k + 1) ans++;
    }
    cout << ans << endl;
    return 0;
}