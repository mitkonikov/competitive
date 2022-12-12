#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> seen;
    seen.insert(s.substr(0, 2));
    for (int i = 3; i < n; i++) {
        string cur = s.substr(i - 1, 2);
        if (seen.count(cur)) {
            cout << "YES" << endl;
            return;
        }
        string prev = s.substr(i - 2, 2);
        seen.insert(prev);
    }
    cout << "NO" << endl;
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