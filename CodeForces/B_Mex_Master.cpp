#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    int z = 0, o = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 0) z++;
        if (A[i] == 1) o++;
    }
    if (z == N) {
        cout << 1 << endl;
        return;
    }
    if (z > N / 2 + (N % 2 == 1)) {
        // it's sure >=1
        if (z == 2 && o == 1) {
            cout << 0 << endl;
            return;
        }
        if (z + o == N) {
            // 010101010010101
            cout << 2 << endl;
            return;
        }
        // 00000021
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
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