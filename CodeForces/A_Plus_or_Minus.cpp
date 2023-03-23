#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) {
        cout << "+" << endl;
    } else {
        cout << "-" << endl;
    }
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