#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int r, c;
    cin >> r >> c;

    int R = 2 * r + 1;
    int C = 2 * c + 1;
    char mat[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            mat[i][j] = '.';
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (j % 2 == 0) mat[i][j] = '|';
            if (i % 2 == 0 && j % 2 == 1) mat[i][j] = '-';
            if (j % 2 == 0 && i % 2 == 0) mat[i][j] = '+';
        }
    }

    mat[0][0] = '.';
    mat[0][1] = '.';
    mat[1][0] = '.';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << mat[i][j];
        } cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt + 1 << ":" << endl;
        testCase();
    }

    return 0;
}