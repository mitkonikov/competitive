#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    bool nok = ((X & Y) != (X & Z) || (X & Y) != (Y & Z));
    cout << (nok ? "NO" : "YES") << endl;
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