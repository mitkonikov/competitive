// Task: https://mendo.mk/Task.do?id=195

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans + mp[x - a[i]];
        mp[a[i]]++;
    }

    cout << ans << endl;
    return 0;
}