// Task: https://mendo.mk/Task.do?id=73

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll k;
    cin >> k;

    ll powers[62];
    powers[0] = 1;
    for (int i = 1; i < 62; i++) {
        powers[i] = powers[i-1] * 2;
    }

    string res = "";
    while (k > 0) {
        for (int i = 1; i <= 60; i++) {
            ll power = powers[i] - 1;
            if (k < power) {
                ll last_power = powers[i-1] - 1;
                if (k - last_power >= powers[i-2]) {
                    res += "7";
                    k -= powers[i-2];
                } else {
                    res += "4";
                }
                k -= powers[i-2];
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}