#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<string> rotate(const vector<string>& matrix, int x, int y) {
    vector<string> result(x, string(y, '.'));

    int newColumn, newRow = 0;
    for (int oldColumn = x - 1; oldColumn >= 0; oldColumn--) {
        newColumn = 0;
        for (int oldRow = 0; oldRow < y; oldRow++) {
            result[newRow][newColumn] = matrix[oldRow][oldColumn];
            newColumn++;
        }
        newRow++;
    }

    return result;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = INT_MAX;
    for (int rep: { 0, 1 }) {
        if (K <= M) {
            for (int i = 0; i < N; i++) {
                int count = 0;
                int xs = 0;
                for (int j = 0; j < K; j++) {
                    count += (A[i][j] == 'o');
                    xs += (A[i][j] == 'x');
                }
                if (xs == 0) ans = min(ans, K - count);
                for (int jj = K; jj < M; jj++) {
                    count -= (A[i][jj-K] == 'o');
                    xs -= (A[i][jj-K] == 'x');
                    count += (A[i][jj] == 'o');
                    xs += (A[i][jj] == 'x');
                    if (xs == 0) ans = min(ans, K - count);
                }
            }

            if (rep == 1) {
                break;
            }
        }

        A = rotate(A, M, N);
        swap(M, N);
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}