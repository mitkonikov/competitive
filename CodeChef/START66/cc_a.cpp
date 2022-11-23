#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m, k;
    cin >> n >> m >> k;
    int x;
    cin >> x;
    x--;
    ll cycle = n * k + m;
    x %= cycle;
    if (x >= n * (k - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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