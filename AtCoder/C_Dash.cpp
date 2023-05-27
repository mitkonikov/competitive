#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const int ch[4] = { 'D', 'U', 'L', 'R' };

int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int, int>> points;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        points.insert({ x, y });
    }
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        for (int dir = 0; dir < 4; dir++) {
            if (ch[dir] == S[i]) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                H--;
                if (H < 0) {
                    cout << "No" << endl;
                    return 0;
                }
                if (points.count({ nx, ny })) {
                    if (H < K) {
                        points.erase({ nx, ny });
                        H = K;
                    }
                }
                x = nx;
                y = ny;
                break;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}