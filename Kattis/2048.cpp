#include <bits/stdc++.h>

using namespace std;

void shiftLeft(vector<vector<int>> &mat) {
    for (int i = 0; i < 4; i++) {
        vector<int> newVec;
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] != 0) newVec.push_back(mat[i][j]);
        }

        for (int j = newVec.size(); j < 4; j++) {
            newVec.push_back(0);
        }

        mat[i] = newVec;
    }
}

vector<vector<int>> rotate(const vector<vector<int>>& win, int x, int y) {
    vector<vector<int>> result(x, vector<int>(y, 0));

    int newColumn, newRow = 0;
    for (int oldColumn = x - 1; oldColumn >= 0; oldColumn--) {
        newColumn = 0;
        for (int oldRow = 0; oldRow < y; oldRow++) {
            result[newRow][newColumn] = win[oldRow][oldColumn];
            newColumn++;
        }
        newRow++;
    }

    return result;
}

vector<vector<int>> rotateTimes(const vector<vector<int>> &mat, int times) {
    vector<vector<int>> result = mat;
    for (int i = 0; i < times; i++) {
        result = rotate(result, 4, 4);
    }
    return result;
}

void printMat(const vector<vector<int>> &mat) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat(4, vector<int>(4, 0));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }

    int op;
    cin >> op;

    mat = rotateTimes(mat, op);

    shiftLeft(mat);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3;) {
            if (mat[i][j] == mat[i][j+1]) {
                mat[i][j] *= 2;
                mat[i][j+1] = 0;
                j += 2;
            } else {
                j++;
            }
        }
    }

    shiftLeft(mat);

    mat = rotateTimes(mat, 4 - op);

    printMat(mat);

    return 0;
}