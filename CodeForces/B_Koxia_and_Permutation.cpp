#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    int L = 0, R = N - 1;
    for (int i = 0; i < N; i++) {
        if (i & 1) {
            cout << L + 1 << " ";
            L++;
        } else {
            cout << R + 1 << " ";
            R--;
        }
    }
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