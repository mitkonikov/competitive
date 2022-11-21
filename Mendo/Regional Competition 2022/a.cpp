#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int x, n;
    cin >> n >> x;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += x * i;
    }
    cout << ans << endl;
    return 0;
}