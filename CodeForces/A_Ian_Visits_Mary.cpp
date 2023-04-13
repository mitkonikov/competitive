#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << 1 << endl;
        cout << a << " " << b << endl;
        return;
    }
    cout << 2 << endl;
    cout << a - 1 << " " << 1 << endl;
    cout << a << " " << b << endl;
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