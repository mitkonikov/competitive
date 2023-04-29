#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> sieve(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sieve[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = ans + (ll)i * (sieve[i] + 1);
    }

    cout << ans << endl;
    return 0;
}