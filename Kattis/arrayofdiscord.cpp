#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool changed = false;
    for (int i = 0; i < n; i++) {
        string s = to_string(a[i]);
        int d = 0;
        while (d + 1 < s.size() && s[d] == '9') d++;
        s[d] = '9';
        if (i + 1 < n && atoll(s.c_str()) > a[i+1]) {
            a[i] = atoll(s.c_str());
            changed = true;
            break;
        }

        s = to_string(a[i]);
        d = 0;
        if (s.size() == 1) {
            s = "0";
        } else {
            if (s[d] == '1') {
                d++;
                while (d + 1 < s.size() && s[d] == '0') d++;
                s[d] = '0';
            } else {
                s[d] = '1';
            }
        }
        if (i - 1 >= 0 && atoll(s.c_str()) < a[i-1]) {
            a[i] = atoll(s.c_str());
            changed = true;
            break;
        }
    }

    if (!changed) {
        cout << "impossible" << endl;
        return 0;
    }

    for (auto v: a) cout << v << " "; 
    cout << endl;
    return 0;
}