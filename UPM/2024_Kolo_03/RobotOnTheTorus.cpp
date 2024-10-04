#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
int main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    string S;
    cin >> S;
    vector<string> ans(A);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '#') ans[i][j] = '#';
            else ans[i][j] = '.';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans[i][j] == '.') {
                bool ok = false;
                for (int sdir = 0; sdir < 4; sdir++) {
                    int x = i, y = j;
                    int current_dir = sdir;
                    for (int l = 0; l < L; l++) {
                        if (S[l] == 'F') {
                            int nx = (x + dx[current_dir] + N) % N;
                            int ny = (y + dy[current_dir] + M) % M;
                            if (A[nx][ny] != '#') {
                                x = nx;
                                y = ny;
                            }
                        } else if (S[l] == 'L') {
                            current_dir = (current_dir + 1 + 4) % 4;
                        } else if (S[l] == 'R') {
                            current_dir = (current_dir - 1 + 4) % 4;
                        }
                    }
                    if (A[x][y] == '*') {
                        ok = true;
                        break;
                    }
                }
                if (ok) ans[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
    return 0;
}