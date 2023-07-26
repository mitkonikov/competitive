#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int front = 0, back = N - 1;
    int cf = 0, cb = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == A[0]) cf++;
        if (cf == K) {
            front = i;
            break;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == A[N - 1]) cb++;
        if (cb == K) {
            back = i;
            break;
        }
    }
    if (A[0] == A[N - 1] && (cf == K || cb == K)) {
        cout << "YES" << endl;
        return;
    }
    cout << (cf == K && cb == K && front < back ? "YES" : "NO") << endl;
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