#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<vector<bool>> mat(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x) mat[i][j] = 1;
        }
    }
    if (N == 1) {
        cout << "YES" << endl;
        return;
    }
    int mismatches = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] != mat[N-i-1][N-j-1] && !(i == N-i-1 && j == N-j-1)) {
                mismatches++;
            }
        }
    }
    mismatches /= 2;
    if (K < mismatches) {
        cout << "NO" << endl;
        return;
    }
    if (N % 2 == 1) {
        cout << "YES" << endl;
        return;
    }
    if ((K - mismatches) % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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