#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string s;
    cin >> s;
    int sum = 0;
    for (auto el: s) sum += (el - '0');
    sum %= 9;
    if (sum == 0) {
        cout << s << endl;
        return;
    }
    sum = 9 - sum;
    ll ans = LLONG_MAX;
    int n = s.size();
    for (int i = 0; i < n + 1; i++) {
        string ns = s;
        ns.insert(ns.begin() + i, (char)('0' + sum));
        ll nl = stoll(ns);
        ans = min(ans, nl);
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