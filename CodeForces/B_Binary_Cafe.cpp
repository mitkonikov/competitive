#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b;
    cin >> a >> b;
    if (a >= (1 << min(30, b))) {
        cout << (1 << b) << endl;
    } else {
        cout << a + 1 << endl;
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