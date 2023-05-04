#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    const ll MOD = 1e9 + 7;
    ll N;
    cin >> N;
    ll F1 = 0, F2 = 1;
    for (int i = 1; i <= N; i++) {
        ll current = (i - 1) * (F1 + F2) % MOD;
        F1 = F2;
        F2 = current;
    }
    cout << F2 << endl;
    return 0;
}