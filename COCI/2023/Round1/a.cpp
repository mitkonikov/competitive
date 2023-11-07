#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<string> A(13);
    for (int i = 0; i < 13; i++) {
        cin >> A[i];
    }
    vector<vector<int>> sudoku(9, vector<int>(9, -1));
    int x = 0, y = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if ((A[i][j] >= '0' && A[i][j] <= '9') || A[i][j] == '.') {
                if (A[i][j] != '.') {
                    sudoku[x][y] = A[i][j] - '0';
                }
                y++;
                if (y == 9) {
                    x++;
                    y = 0;
                }
            }
        }
    }
    bool ok = 1;
    for (int i = 0; i < 9; i++) {
        set<int> visited;
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] != -1 && visited.count(sudoku[i][j])) ok = 0;
            visited.insert(sudoku[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        set<int> visited;
        for (int j = 0; j < 9; j++) {
            if (sudoku[j][i] != -1 && visited.count(sudoku[j][i])) ok = 0;
            visited.insert(sudoku[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            set<int> visited;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int value = sudoku[i * 3 + k][j * 3 + l];
                    if (value != -1 && visited.count(value)) {
                        ok = 0;
                    }
                    visited.insert(value);
                }
            }
        }
    }
    cout << (ok ? "OK" : "GRESKA") << endl;
    return 0;
}