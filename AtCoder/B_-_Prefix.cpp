#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    if (s.size() > t.size()) {
        cout << "No" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}