#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, A, B;
    cin >> N >> A >> B;
    if (N == 2) {
        cout << "NO" << endl;
        return;
    }
    if ((A == 1 && B == 2) || (A == N && B == N - 1)) {
        cout << "NO" << endl;
        return;
    }
    if (B > A) {
        cout << ((B - A) % 2 == 0 ? "YES" : "NO") << endl;
    } else {
        cout << ((A - B) % 2 == 0 ? "YES" : "NO") << endl;
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