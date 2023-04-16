#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
vector<vector<T>> rotateMatrix(const vector<vector<T>>& matrix, int x, int y) {
    vector<vector<T>> result(x, vector<T>(y, 0));

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
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<int>> B(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    for (int R = 0; R < 4; R++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] && B[i][j] == 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }

        A = rotateMatrix<int>(A, N, N);
    }

    cout << "No" << endl;
    return 0;
}