#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            A[i][j] = S[j] - '0';
        }
    }
    vector<vector<int>> pref(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) pref[i][j] = A[i][j];
            else if (i == 0) {
                pref[i][j] = pref[i][j-1] + A[i][j];
            } else if (j == 0) {
                pref[i][j] = pref[i-1][j] + A[i][j];
            } else {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + A[i][j];
            }
        }
    }
    vector<vector<int>> mat(H, vector<int>(W, 0));
    vector<vector<bool>> visited(H, vector<bool>(W, 0));
    int L = 0, R = min(H, W) + 1;
    while (R - L > 1) {
        int MID = (R + L) / 2;
        int CH = H - MID + 1;
        int CW = W - MID + 1;
        for (int i = 0; i < CH; i++) {
            for (int j = 0; j < CW; j++) {
                visited[i][j] = false;
                mat[i][j] = pref[i + MID - 1][j + MID - 1];
                if (i>0) mat[i][j] -= pref[i - 1][j + MID - 1];
                if (j>0) mat[i][j] -= pref[i + MID - 1][j - 1];
                if (i>0&&j>0) mat[i][j] += pref[i - 1][j - 1];
            }
        }

        if (mat[0][0] > 0) {
            R = MID;
            continue;
        }

        queue<pair<int, int>> bfs;
        bfs.push({ 0, 0 });
        visited[0][0] = 1;
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < CH && ny < CW) {
                    if (!visited[nx][ny] && mat[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        bfs.push({ nx, ny });
                    }
                }
            }
        }
        
        if (visited[CH - 1][CW - 1]) {
            L = MID;
        } else {
            R = MID;
        }
    }
    cout << L << endl;
    return 0;
}