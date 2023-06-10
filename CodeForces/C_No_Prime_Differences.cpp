#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

bool prime(int N) {
    if (N == 1) return false;
    if (N == 2) return true;
    for (int i = 2; i * i <= N; i++) if (N % i == 0) return false;
    return true;
}

void testCase() {
    int N, M;
    cin >> N >> M;
    bool swapped = 0;
    vector<vector<int>> A;
    if (prime(N) && prime(M)) {
        A.resize(N, vector<int>(M, 0));
        int c = 1;
        for (int i = 0, cr = 0; cr < N; cr++, i=(i+2)%N) {
            for (int j = 0; j < M; j++) {
                A[i][j] = c++;
            }
        }
    } else {
        if (prime(N)) {
            swapped = 1;
            swap(N, M);
        }
        A.resize(N, vector<int>(M, 0));
        int c = 1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                A[j][i] = c++;
            }
        }
    }

    if (swapped) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[j][i] << " ";
            } cout << endl;
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << A[i][j] << " ";
            } cout << endl;
        }
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