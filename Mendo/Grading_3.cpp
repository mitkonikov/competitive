#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll L = 1, R = (ll)200000000000 * 200;
    ll last_ok = 1;
    while (R - L > 1) {
        ll mid = (R - L) / 2 + L;
        ll graded = 0;
        for (int i = 0; i < n; i++) {
            graded += mid / s[i];
        }
        if (graded >= k) {
            R = mid;
            last_ok = mid;
        } else {
            L = mid;
        }
    }
    cout << last_ok << endl;
    return 0;
}