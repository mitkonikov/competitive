#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int A, B;
    cin >> A >> B;
    if (A == 1) {
        if (B == 2) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        cout << 1 << endl;
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