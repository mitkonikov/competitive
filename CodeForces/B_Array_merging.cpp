#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<vector<int>> whereA(2 * N + 1), whereB(2 * N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        whereA[A[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        whereB[B[i]].push_back(i);
    }
    int ans = 1;
    for (int i = 0; i < 2 * N + 1; i++) {
        int lA = 0, cA = 0;
        int lB = 0, cB = 0;
        for (int j = 0; j < whereA[i].size(); j++) {
            if (j == 0 || whereA[i][j] == whereA[i][j-1] + 1) {
                cA++;
            } else {
                lA = max(lA, cA);
                cA = 1;
            }
        }
        for (int j = 0; j < whereB[i].size(); j++) {
            if (j == 0 || whereB[i][j] == whereB[i][j-1] + 1) {
                cB++;
            } else {
                lB = max(lB, cB);
                cB = 1;
            }
        }
        lA = max(lA, cA);
        lB = max(lB, cB);
        ans = max(ans, lA + lB);
    }
    cout << ans << endl;
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