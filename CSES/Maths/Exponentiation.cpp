#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
const ll MOD = 1e9 + 7;
ll expo(ll b, ll e) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % MOD;
            e--;
            continue;
        }
 
        b = (b * b) % MOD;
        e /= 2;
    }
    return result;
}
 
int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll b, e;
        cin >> b >> e;
        cout << expo(b, e) << endl;
    }
    return 0;
}