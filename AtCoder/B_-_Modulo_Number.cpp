#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll N;
    cin >> N;
    const ll MOD = 998244353;
    cout << ((N % MOD) + MOD) % MOD << endl;
    cout << flush;
    return 0;
}