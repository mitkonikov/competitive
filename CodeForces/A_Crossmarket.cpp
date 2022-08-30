#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    
    if (n > m) {
        cout << m + (m - 1) + (n - 1) << endl;
    } else {
        cout << n + (n - 1) + (m - 1) << endl;
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