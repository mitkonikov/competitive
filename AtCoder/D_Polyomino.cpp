#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> read() {
    vector<string> A(4);
    for (int i = 0; i < 4; i++) cin >> A[i];
    // int xmn = 10, xmx = 0, ymn = 10, ymx = 0;
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         if (A[i][j] == '#') {
    //             xmn = min(xmn, i);
    //             xmx = max(xmx, i);
    //             ymn = min(ymn, i);
    //             ymx = max(ymx, j);
    //         }
    //     }
    // }
    // vector<string> res(xmx - xmn + 1);
    // for (int i = xmn; i <= xmx; i++) {
    //     for (int j = ymn; j <= ymx; j++) {
    //         res[i - xmn].push_back(A[i][j]);
    //     }
    // }
    return A;
}

int count(vector<string>& A) {
    int c = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            c += (A[i][j] == '#');
        }
    }
    return c;
}

vector<string> rotate(const vector<string>& matrix, int x, int y) {
    vector<string> result(x, string(y, 0));

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

bool put(vector<string> toput, vector<string> base, function<bool(vector<string>)> rec) {
    for (int i = -3; i < 4; i++) {
        for (int j = -3; j < 4; j++) {
            bool f = 0;
            for (int k = 0; k < 4 && !f; k++) {
                for (int l = 0; l < 4 && !f; l++) {
                    if ((i+k < 0 || j+l < 0)) {
                        if (toput[k][l] == '#') {
                            f = 1;
                            break;
                        }
                    } else if ((i+k >= 4 || j+l >= 4)) {
                        if (toput[k][l] == '#') {
                            f = 1;
                            break;
                        }
                    } else {
                        if (toput[k][l] == '#' && base[i+k][j+l] == '#') {
                            f = 1;
                            break;
                        }
                    }
                }
            }
            if (!f) {
                vector<string> copy(base);
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        if (toput[k][l] == '#' && (i+k>=0&&j+l>=0&&i+k<4&&j+l<4)) copy[i+k][j+l] = '#';
                    }
                }

                if (rec(copy)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void print(char c, vector<string> a) {
    cout << "  ---- " << c << " --- " << endl;
    for (int i =0 ; i < 4; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    auto A = read();
    auto B = read();
    auto C = read();
    auto AC = count(A);
    auto BC = count(B);
    auto CC = count(C);
    if (AC + BC + CC != 16) {
        cout << "No" << endl;
        return 0;
    }
    vector<string> empty(4, string(4, '.'));
    for (int ra = 0; ra < 4; ra++) {
        for (int rb = 0; rb < 4; rb++) {
            for (int rc = 0; rc < 4; rc++) {
                bool ok = put(A, empty, [&](vector<string> mat) -> bool {
                    return put(B, mat, [&](vector<string> mat1) -> bool {
                        return put(C, mat1, [&](vector<string> mat2) -> bool {
                            return true;
                        });
                    });
                });

                if (ok) {
                    cout << "Yes" << endl;
                    return 0;
                }

                C = rotate(C, 4, 4);
            }
            B = rotate(B, 4, 4);
        }
        A = rotate(A, 4, 4);
    }
    cout << "No" << endl;
    return 0;
}