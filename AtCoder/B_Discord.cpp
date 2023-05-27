#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    swap(N, M);
    vector<vector<int>> mat(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for (int a = 1; a <= M; a++) {
        for (int b = a + 1; b <= M; b++) {
            bool ok = 0;
            for (int i = 0; i < N && !ok; i++) {
                for (int j = 0; j < M - 1 && !ok; j++) {
                    if (mat[i][j] == a && mat[i][j+1] == b) {
                        ok = true;
                    }
                    if (mat[i][j] == b && mat[i][j+1] == a) {
                        ok = true;
                    }
                }
            }
            if (!ok) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}