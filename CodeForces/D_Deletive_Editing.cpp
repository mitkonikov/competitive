#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string s, t;
    cin >> s >> t;

    vector<int> frq(26, 0);
    for (int i = 0; i < t.size(); i++) frq[t[i] - 'A']++;

    int p1 = t.size() - 1;
    bool ok = true;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == t[p1]) {
            frq[t[p1] - 'A']--;
            p1--;
        } else if (frq[s[i] - 'A'] != 0) {
            ok = false;
            break;
        }
    }

    ok = (p1 == -1);
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}