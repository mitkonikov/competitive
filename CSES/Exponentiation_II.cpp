#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const ll MOD = 1e9 + 7;
ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
            e--;
            continue;
        }

        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << expo(a, expo(b, c, MOD - 1), MOD) << endl;
    }
    return 0;
}