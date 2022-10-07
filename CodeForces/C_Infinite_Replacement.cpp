#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string s, t;
    cin >> s >> t;

    string tmp = t;
    sort(tmp.begin(), tmp.end());
    if (tmp.front() == 'a' && t.size() >= 2) {
        cout << -1 << endl;
        return;
    }

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') count++;
    }

    if (s.size() == count) {
        if (tmp.front() == 'a') {
            cout << 1 << endl;
            return;
        }
    }

    cout << (1LL << count) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}