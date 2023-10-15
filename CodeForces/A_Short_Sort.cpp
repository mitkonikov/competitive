#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string s;
    cin >> s;
    if (s == "bca" || s == "cab") cout << "NO" << endl;
    else cout << "YES" << endl;
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