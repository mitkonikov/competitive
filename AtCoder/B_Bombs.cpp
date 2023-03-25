#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(N, string(M, '.'));
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<pair<int, int>> bombs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '#') B[i][j] = '#';
            if (A[i][j] != '#' && A[i][j] != '.') bombs.push_back({ i, j });
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[i][j] == '#') {
                for (auto [x, y]: bombs) {
                    if (abs(x - i) + abs(y - j) <= A[x][y] - '0') {
                        B[i][j] = '.';
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << B[i] << endl;
    }
    return 0;
}