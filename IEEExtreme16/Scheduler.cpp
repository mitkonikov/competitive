#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

long long binary(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
            power--;
        }

        base = (base * base) % MOD;
        power /= 2;
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    ll sum = 0;
    int mx = 0;
    vector<int> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i];
        sum = (sum + binary(2, jobs[i])) % MOD;
        mx = max(mx, jobs[i]);
    }

    if (m == 1) {
        cout << sum << endl;
    } else {
        cout << binary(2, mx) << endl;
    }
    return 0;
}