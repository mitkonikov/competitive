#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void testCase() {
    int X, Y;
    cin >> X >> Y;
    vector<string> A(X);
    for (int i = 0; i < X; i++) cin >> A[i];
    int id = 1;
    vector<vector<int>> comp(X, vector<int>(Y, 0));
    vector<vector<int>> there(X, vector<int>(Y, 0));
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (comp[i][j] == 0 && A[i][j] == 'W') {
                queue<pair<int, int>> bfs;
                bfs.push({ i, j });
                pair<int, int> e;
                int count = 0;
                set<pair<int, int>> s_empty;
                while (!bfs.empty()) {
                    auto [x, y] = bfs.front();
                    bfs.pop();
                    if (comp[x][y] != 0) continue;
                    count++;
                    comp[x][y] = id;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (valid(nx, ny, X, Y) && comp[nx][ny] == 0) {
                            if (A[nx][ny] == 'W') {
                                bfs.push({ nx, ny });
                            } else if (A[nx][ny] == '.') {
                                s_empty.insert({ nx, ny });
                                e = { nx, ny };
                            }
                        }
                    }
                }

                if (s_empty.size() == 1) there[e.first][e.second] += count;

                id++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            ans = max(ans, there[i][j]);
        }
    }
    cout << (ans > 0 ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}