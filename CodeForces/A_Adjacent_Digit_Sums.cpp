#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int X, Y;
    cin >> X >> Y;
    if (X == Y) {
        cout << "No" << endl;
        return;
    }
    for (int k = 0; k * 9 <= X; k++) {
        int rem = X - k * 9 + 1;
        if (rem == Y) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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