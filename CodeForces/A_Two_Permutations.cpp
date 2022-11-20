#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1 && a == 1 && b == 1) {
        cout << "Yes" << endl;
        return;
    }

    if (a + b == n) {
        cout << "No" << endl;
        return;
    }

    if ((a + b < n && (n - a - b != 1)) || (a == b && a == n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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