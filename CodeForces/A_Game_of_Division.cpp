#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> M(K + 10);
    for (int i = 0; i < N; i++) {
        M[A[i] % K]++;
    }
    for (int i = 0; i < K; i++) {
        if (M[i] == 1) {
            cout << "YES" << endl;
            for (int j = 0; j < N; j++) {
                if (A[j] % K == i) {
                    cout << j + 1 << endl;
                    break;
                }
            }
            return;
        }
    }
    cout << "NO" << endl;
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