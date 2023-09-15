#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 9 + 1; i++) {
        for (int j = 0; j < M - 9 + 1; j++) {
            bool ok = 1;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    ok &= (A[i+k][j+l] == '#');
                }
            }
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    ok &= (A[i+9-k-1][j+9-l-1] == '#');
                }
            }
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (k == 3 || l == 3)
                        ok &= (A[i+k][j+l] == '.');
                }
            }
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (k == 3 || l == 3)
                        ok &= (A[i+9-k-1][j+9-l-1] == '.');
                }
            }
            if (ok) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}