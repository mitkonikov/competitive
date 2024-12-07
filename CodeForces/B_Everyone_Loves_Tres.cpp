#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << -1 << endl;
        return;
    }
    if (N == 2) {
        cout << 66 << endl;
        return;
    }
    if (N == 3) {
        cout << -1 << endl;
        return;
    }
    if (N == 4) {
        cout << 3366 << endl;
        return;
    }
    if (N % 2 == 0) {
        for (int i = 0; i < N - 2; i++) {
            cout << 3;
        }
        cout << 66 << endl;
    } else {
        for (int i = 0; i < N - 4; i++) {
            cout << 3;
        }
        cout << 6366 << endl;
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