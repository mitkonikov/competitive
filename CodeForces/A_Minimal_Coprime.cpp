#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int A, B;
    cin >> A >> B;
    if (A == B && A == 1) {
        cout << 1 << endl;
        return;
    }
    cout << B - A << endl;
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