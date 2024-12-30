#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bool ok = false;
    for (int i = 0; i < N - 1; i++) {
        int j = i + 1;
        if (2 * A[i] > A[j] && 2 * A[j] > A[i]) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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