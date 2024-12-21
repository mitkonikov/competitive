#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const int ch[4] = { 'L', 'R', 'U', 'D' };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void testCase() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    string T;
    cin >> T;
    set<pair<int, int>> houses;
    X--; Y--;
    for (int i = 0; i < T.size(); i++) {
        for (int dir = 0; dir < 4; dir++) {
            if (ch[dir] == T[i]) {
                int nx = X + dx[dir];
                int ny = Y + dy[dir];
                if (valid(nx, ny, N, M) && (A[nx][ny] != '#')) {
                    X = nx;
                    Y = ny;
                    if (A[X][Y] == '@') {
                        houses.insert({ X, Y });
                    }
                }
                break;
            }
        }
    }
    cout << X + 1 << " " << Y + 1 << " " << (int)houses.size() << endl;
}

int main() {
    testCase();
    return 0;
}