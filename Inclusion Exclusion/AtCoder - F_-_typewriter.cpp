#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int MOD = 998244353;

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

int count(string s, int n) {
    int frq[26];
    for (int i = 0; i < 26; i++) frq[i] = 0;
    for (int i = 0; i < s.size(); i++) frq[s[i] - 'a']++;
    int count = 0;
    for (int i = 0; i < 26; i++) if (frq[i] == n) count++;
    return count;
}

int main() {
    ll n, l;
    cin >> n >> l;


    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    ll ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        string conc = "";
        int bit_count = 0;
        for (int bit = 0; bit < n; bit++) {
            if ((1 << bit) & i) {
                conc += s[bit];
                bit_count++;
            }
        }

        int lett = count(conc, bit_count);
        if (bit_count % 2 == 0) {
            ans = (ans - binary(lett, l) + MOD) % MOD;
        } else {
            ans = (ans + binary(lett, l)) % MOD;
        }
    }

    cout << (ans + MOD) % MOD << endl;
    return 0;
}