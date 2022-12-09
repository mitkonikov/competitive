#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int match = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        if (v[i] == i) match++;
    }

    ll ans = ((ll)match * (match - 1) / 2);
    for (int i = 0; i < n; i++) {
        ans += (v[i] > i && v[v[i]] == i);
    }
    cout << ans << endl;
    return 0;
}