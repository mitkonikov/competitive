#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    for (int row = 0; row < n; row++) {
        for (int j = 0; j < row + 1; j++) {
            if (j == 0 || j == row) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
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