#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> mat(N, vector<bool>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == 'o') mat[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool ok = true;
            for (int k = 0; k < M; k++) {
                ok &= (mat[i][k] | mat[j][k]);
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}