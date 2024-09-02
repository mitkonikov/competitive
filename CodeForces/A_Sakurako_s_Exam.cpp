#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b;
    cin >> a >> b;
    if (a % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    if (a % 2 == 0 && b % 2 == 0) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (((a - i) - i + 2 * ((b - j) - j)) == 0) {
                cout << "YES" << endl;
                return;
            }
        }
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