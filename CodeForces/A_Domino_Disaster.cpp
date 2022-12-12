#include <bits/stdc++.h>

using namespace std;

void testCase() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            cout << "D";
        } else if (s[i] == 'D') {
            cout << "U";    
        } else {
            cout << "LR";
            i++;
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

    return 0;
}