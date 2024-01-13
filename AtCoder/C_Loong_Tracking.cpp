#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
const char c[4] = { 'D', 'U', 'L', 'R'};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> queue(N);
    for (int i = 0; i < N; i++) queue[i] = { i + 1, 0 };
    int head = 0;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            char d;
            cin >> d;
            for (int dir = 0; dir < 4; dir++) {
                if (c[dir] == d) {
                    int nx = queue[head].first + dx[dir];
                    int ny = queue[head].second + dy[dir];
                    queue[(head - 1 + N) % N] = { nx, ny };
                    head = (head - 1 + N) % N;
                }
            }
        } else {
            int p;
            cin >> p;
            p--;
            auto [x, y] = queue[(head + p) % N];
            cout << x << " " << y << endl;
        }
    }
    return 0;
}