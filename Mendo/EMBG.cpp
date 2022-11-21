// Task: https://mendo.mk/Task.do?id=967

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool is_palindrome(const string &s, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (n - 1 - i < s.size() && s[i] != s[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<string> pref(p);
    for (int i = 0; i < p; i++) cin >> pref[i];

    sort(pref.begin(), pref.end(), [&](const string &a, const string &b) {
        if (a.size() == b.size()) return (a < b);
        return (a.size() < b.size());
    });

    vector<string> cleared;
    for (int i = 0; i < p; i++) {
        bool ok = true;
        for (int j = 0; j < cleared.size(); j++) {
            if (pref[i].substr(0, cleared[j].size()) == cleared[j]) {
                ok = false;
                break;
            }
        }

        if (ok) cleared.push_back(pref[i]);
    }

    ll powers[18];
    powers[0] = 1;
    for (int i = 1; i <= n; i++) powers[i] = powers[i - 1] * 10;

    ll ans = powers[n];

    ll forbidden = 0;
    for (int i = 0; i < cleared.size(); i++) {
        if (cleared[i].size() > n / 2 + (n % 2 == 1) && is_palindrome(cleared[i], n)) forbidden--;
        forbidden = forbidden + powers[n - cleared[i].size()];
    }

    ll pal = powers[n / 2 + (n % 2 == 1)];
    for (int i = 0; i < cleared.size(); i++) {
        int id = n / 2 + (n % 2 == 1) - cleared[i].size();
        if (id < 0) continue;
        pal = pal - powers[id];
    }

    cout << ans - pal - forbidden << endl;

    return 0;
}