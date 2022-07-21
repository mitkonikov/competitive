#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll n;
    cin >> n;
    string s = to_string(n);
    ll ans = 0;
    ll power[20]; power[0] = 1;
    for (int i = 1; i < 19; i++) {
        power[i] = power[i-1] * 10;
    }
    for (int i = 1; i <= s.size() / 2; i++) {
        ll L = power[i-1] - 1, R = power[i];
        while (R - L > 1) {
            ll mid = L + (R - L) / 2;
            string sub = to_string(mid);
            string sub_init = sub;
            int init = sub.size();
            while (sub.size() + init <= s.size()) {
                sub = sub + sub_init;
            }

            try {
                ll num = stoll(sub);
                if (num <= n) {
                    L = mid;
                    ans = max(ans, num);
                    // cout << num << endl;
                } else {
                    R = mid;
                }
            } catch (exception e) {
                R = mid;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}