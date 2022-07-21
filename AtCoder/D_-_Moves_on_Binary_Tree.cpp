#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<int> bits;
    ll tmp = x;
    while (tmp > 0) {
        bits.push_back(tmp % 2);
        tmp /= 2LL;
    }

    reverse(bits.begin(), bits.end());
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            bits.pop_back();
        } else if (s[i] == 'R') {
            bits.push_back(1);
        } else {
            bits.push_back(0);
        }
    }

    ll ans = 0;
    for (int i = 0; i < bits.size(); i++) {
        if (bits[bits.size() - 1 - i] == 1) {
            ans += (1LL << i);
        }
    }
    cout << ans << endl << flush;
    return 0;
}