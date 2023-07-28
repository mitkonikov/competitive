#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = false;
    ok |= (a + b >= 10);
    ok |= (c + b >= 10);
    ok |= (a + c >= 10);
    cout << (ok ? "YES" : "NO") << endl;
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