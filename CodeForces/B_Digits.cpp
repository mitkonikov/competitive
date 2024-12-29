#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, D;
    cin >> N >> D;
    cout << 1 << " ";
    if (N >= 3 || D == 3 || D == 6 || D == 9) cout << 3 << " ";
    if (D == 5) cout << 5 << " ";
    if (N >= 3 || D == 7) cout << 7 << " ";
    if (N >= 6 || (N >= 3 && D % 3 == 0) || D == 9) cout << 9 << " ";
    cout << endl;
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