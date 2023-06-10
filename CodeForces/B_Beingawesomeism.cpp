#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool corner(int x, int y, int N, int M) {
    if (x == 0 && y == 0) return true;
    if (x == N - 1 && y == 0) return true;
    if (x == 0 && y == M - 1) return true;
    if (x == N - 1 && y == M - 1) return true;
    return false;
}

inline bool is_edge(int x, int y, int N, int M) {
    if (x == 0) return true;
    if (y == 0) return true;
    if (x == N - 1) return true;
    if (y == M - 1) return true;
    return false;
}

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        bool f = 1;
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'A') {
                if (corner(i, j, N, M)) ans = min(ans, 2);
                if (is_edge(i, j, N, M)) ans = min(ans, 3);
                ans = min(ans, 4);
            } else {
                f = 0;
            }
        }
        if (f) {
            if (i == 0 || i == N - 1) ans = min(ans, 1);
            else ans = min(ans, 2);
        }
    }
    bool is_a = 0, is_p = 0;
    for (int j = 0; j < M; j++) {
        bool f = 1;
        for (int i = 0; i < N; i++) {
            if (A[i][j] == 'P') {
                f = 0;
                is_p = 1;
            } else {
                is_a = 1;
            }
        }
        if (f) {
            if (j == 0 || j == M - 1) ans = min(ans, 1);
            else ans = min(ans, 2);
        }
    }
    if (is_p == 0) ans = min(ans, 0);
    if (ans == INT_MAX) cout << "MORTAL" << endl;
    else cout << ans << endl;
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