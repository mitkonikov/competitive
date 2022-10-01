#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll n, m;
    cin >> n >> m;
    cout << (m * (m + 1)) / 2 + m * ((n * (n + 1)) / 2) - m << endl;
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