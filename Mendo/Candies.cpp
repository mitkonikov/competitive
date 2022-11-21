#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> dec;
    int tmp = n;
    while (tmp) {
        int digit = tmp % 3;
        dec.push_back(digit);
        tmp /= 3;
    }

    for (int i = 0; i < 1000; i++) dec.push_back(0);

    vector<int> ans_tino(1000), ans_nino(1000);
    // nino is the one getting the first gift

    int carry = 0;
    for (int i = 0; i < dec.size(); i++) {
        if (dec[i] == 3) {
            dec[i] = 0;
            dec[i+1]++;
        }
        
        if (dec[i] == 2) {
            ans_nino[i] = 1;
            dec[i+1]++;
        } else if (dec[i] == 1) {
            ans_tino[i] = 1;
        }
    }

    ll power = 1;
    bool put_n = false;
    for (int i = 0; i < ans_nino.size(); i++) {
        ll cur_power = power * ans_nino[i];
        if (!put_n && cur_power > n) {
            cout << n << " ";
            put_n = true;
        }

        if (ans_nino[i] > 0) {
            cout << cur_power << " ";
        }

        power *= 3;
    }

    if (!put_n) cout << n << endl;
    else cout << endl;

    power = 1;
    for (int i = 0; i < ans_nino.size(); i++) {
        ll cur_power = power * ans_tino[i];
        if (ans_tino[i] > 0) {
            cout << cur_power << " ";
        }
        
        power *= 3;
    }
}

int main() {
    solve();

    return 0;
}