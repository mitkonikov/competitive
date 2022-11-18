#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string s;
    cin >> s;
    bool ok = false;
    string yes = "Yes";
    for (int k = 0; k < 3; k++) {
        int ss = k;
        bool okk = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != yes[(k + i) % 3]) {
                okk = false;
            }
        }
        if (okk) {
            ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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