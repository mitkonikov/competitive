#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

const int dxd[4] = { 1, -1, 1, -1 };
const int dyd[4] = { 1, -1, -1, 1 };

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> mat(N);
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }
    int T = min(N, M);
    vector<int> ans(T + 1);
    auto valid = [N,M](int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < M);
    };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == '.') continue;
            bool ok = true;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (valid(nx, ny) && mat[nx][ny] == '#') {
                    ok = false;
                }
            }
            if (ok) {
                int ln = INT_MAX;
                bool fail = false;
                for (int dir = 0; dir < 4; dir++) {
                    int stx = i;
                    int sty = j;
                    int len = 0;
                    while (valid(stx, sty) && mat[stx][sty] == '#') {
                        stx = stx + dxd[dir];
                        sty = sty + dyd[dir];
                        len++;
                    }
                    if (len > 1) ln = min(ln, len);
                    else fail = true;
                }
                if (!fail && ln != INT_MAX) ans[ln - 1]++;
            }
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;
    return 0;
}