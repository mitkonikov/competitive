#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<string> A;
int N, M;

const int dx[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < M);
}

string SNUKE = "snuke";
vector<pair<int, int>> ans;

int dfs(int x, int y, int dir, int d = 0) {
    if (d == SNUKE.size()) {
        for (auto [u, v]: ans) {
            cout << u + 1 << " " << v + 1 << endl;
        }
        exit(0);
    }
    if (!valid(x, y)) return 0;
    ans.push_back({ x, y });
    if (A[x][y] == SNUKE[d]) {
        return dfs(x + dx[dir], y + dy[dir], dir, d + 1);
    }
    return 0;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 8; dir++) {
                dfs(i, j, dir);
                ans.clear();
            }
        }
    }
    return 0;
}