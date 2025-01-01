#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll M, A, B, C;
    cin >> M >> A >> B >> C;
    cout << min(C, 2 * M - min(M, A) - min(M, B)) + min(M, A) + min(M, B) << endl;
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