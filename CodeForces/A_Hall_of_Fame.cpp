#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == 'L' && s[i+1] == 'R') {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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