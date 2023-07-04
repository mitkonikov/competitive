#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int AX, AY;
    cin >> AX >> AY;
    vector<string> A(AX);
    for (int i = 0; i < AX; i++) cin >> A[i];
    int BX, BY;
    cin >> BX >> BY;
    vector<string> B(BX);
    for (int i = 0; i < BX; i++) cin >> B[i];
    int CX, CY;
    cin >> CX >> CY;
    vector<string> C(CX);
    for (int i = 0; i < CX; i++) cin >> C[i];
    auto cut_rows = [](vector<string> C) {
        int y = C[0].size();
        for (int i = 0; i < C.size(); i++) {
            if (C[i] == string(y, '.')) {
                C.erase(C.begin() + i);
                i--;
            } else {
                break;
            }
        }
        while (C.back() == string(y, '.')) C.pop_back();
        for (int j = 0; j < C[0].size(); j++) {
            bool cut = 1;
            for (int i = 0; i < C.size(); i++) {
                if (C[i][j] == '#') cut = 0;
            }
            if (cut) {
                for (int i = 0; i < C.size(); i++) {
                    C[i].erase(C[i].begin());
                }
            } else {
                break;
            }
            j--;
        }
        for (int j = C[0].size() - 1; j >= 0; j--) {
            bool cut = 1;
            for (int i = 0; i < C.size(); i++) {
                if (C[i][j] == '#') cut = 0;
            }
            if (cut) {
                for (int i = 0; i < C.size(); i++) {
                    C[i].pop_back();
                }
            } else {
                break;
            }
        }
        return C;
    };
    A = cut_rows(A);
    B = cut_rows(B);
    C = cut_rows(C);
    CX = C.size();
    CY = C[0].size();
    AX = A.size();
    AY = A[0].size();
    BX = B.size();
    BY = B[0].size();
    for (int ax = 0; ax < CX - AX + 1; ax++) {
        for (int ay = 0; ay < CY - AY + 1; ay++) {
            for (int bx = 0; bx < CX - BX + 1; bx++) {
                for (int by = 0; by < CY - BY + 1; by++) {
                    vector<vector<bool>> vis(CX, vector<bool>(CY, 0));
                    for (int x = 0; x < AX; x++) {
                        for (int y = 0; y < AY; y++) {
                            if (A[x][y] == '#') vis[ax+x][ay+y] = true;
                        }
                    }
                    for (int x = 0; x < BX; x++) {
                        for (int y = 0; y < BY; y++) {
                            if (B[x][y] == '#') vis[bx+x][by+y] = true;
                        }
                    }
                    bool f = 0;
                    for (int x = 0; x < CX; x++) {
                        for (int y = 0; y < CY; y++) {
                            if ((C[x][y] == '#' && !vis[x][y]) || (vis[x][y] && C[x][y] == '.')) {
                                f = 1;
                            }
                        }
                    }
                    if (!f) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}