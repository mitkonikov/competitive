#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];

    bool ok = false;
    const int dx[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
    const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int dir = 0; dir < 8; dir++) {
                int left = 2;
                int nx = i;
                int ny = j;
                int count = 0;
                while (nx != -1 && (board[nx][ny] == '#' || (left > 0)) && count < 6) {
                    if (board[nx][ny] == '.') left--;
                    int nnx = nx + dx[dir];
                    int nny = ny + dy[dir];
                    if (valid(nnx, nny, n, n)) {
                        nx = nnx;
                        ny = nny;
                    } else {
                        nx = -1;
                    }

                    count++;
                }

                if (count >= 6) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}