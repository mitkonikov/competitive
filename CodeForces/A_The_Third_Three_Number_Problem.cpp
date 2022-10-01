#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1 << endl;
    } else {
        cout << n / 2 << " 0 0" << endl;
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