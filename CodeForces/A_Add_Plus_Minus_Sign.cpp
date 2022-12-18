#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') count++;
    }
    count /= 2;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            if (count) {
                count--; cout << "-";
            } else cout << "+";
        } else {
            cout << "+";
        }
    }
    cout << endl;
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