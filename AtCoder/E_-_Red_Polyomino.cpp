#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int n, k;

inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

inline void setState(ll& state, int x, int y, bool val) {
    state &= ~(1LL << (x * n + y));
    state |= ((1LL << (x * n + y))) * val;
}

inline bool read(ll& state, int x, int y) {
    return (state & (1LL << (x * n + y)));
}

ll make_hash(vector<string>& v_state) {
    ll result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v_state[i][j] == '@') result |= (1LL << (i * n + j));
        }
    }
    return result;
}

void print_state(ll state) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (read(state, i, j));
        } cout << endl;
    } cout << endl;
}

bool connected(ll hash) {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!read(hash, i, j)) continue;
            if (vis[i][j]) continue;
            comp++;

            queue<pair<int, int>> bfs;
            bfs.push({ i, j });
            while (!bfs.empty()) {
                auto top = bfs.front();
                bfs.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = top.first + dx[dir];
                    int ny = top.second + dy[dir];
                    if (valid(nx, ny) && !vis[nx][ny] && read(hash, nx, ny)) {
                        vis[nx][ny] = true;
                        bfs.push({ nx, ny });
                    }
                }
            }
        }
    }

    return (comp == 1);
}

vector<string> create_state(int i, int j, vector<string>& mat) {
    vector<string> result(n, string(n, '.'));
    queue<pair<int, int>> bfs;
    bfs.push({ i, j });
    result[i][j] = '@';
    int count = 0;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        if (count == k) {
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = top.first + dx[dir];
            int ny = top.second + dy[dir];
            if (valid(nx, ny) && mat[nx][ny] != '#' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                bfs.push({ nx, ny });
                if (count == k) {
                    break;
                }
                result[nx][ny] = '@';
                count++;
            }
        }
    }
    return result;
}

bool ng(int x, int y, ll state) {
    bool ok = false;
    for (int dir = 0; dir < 4 && !ok; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (valid(nx, ny) && read(state, nx, ny)) ok = true;
    }
    return ok;
}

int main() {
    cin >> n >> k;

    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];

    if (k == 1) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != '#') count++;
            }
        }
        cout << count << endl;
        return 0;
    }

    unordered_map<ll, bool> visited;

    vector<string> first_state(n, string(n, '.'));

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> first_bfs;
    queue<ll> bfs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && mat[i][j] != '#') {
                first_bfs.push({ i, j });
                
                int count = 0;
                vis[i][j] = true;
                while (!first_bfs.empty()) {
                    auto top = first_bfs.front();
                    first_bfs.pop();
                    count++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = top.first + dx[dir];
                        int ny = top.second + dy[dir];
                        if (valid(nx, ny) && mat[nx][ny] != '#' && !vis[nx][ny]) {
                            first_bfs.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    }
                }

                if (count >= k) {
                    first_state = create_state(i, j, mat);
                    ll h = make_hash(first_state);
                    bfs.push(h);
                    visited[h] = true;
                }
            }
        }
    }

    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (read(top, i, j)) {
                    setState(top, i, j, false);
                    if (!connected(top) || top == 0) {
                        setState(top, i, j, true);
                        continue;
                    }

                    for (int ni = 0; ni < n; ni++) {
                        for (int nj = 0; nj < n; nj++) {
                            if (ni == i && nj == j) continue;
                            if (mat[ni][nj] == '#') continue;
                            if (read(top, ni, nj)) continue;
                            if (!ng(ni, nj, top) && top != 0) continue;
                            
                            setState(top, ni, nj, true);
                            
                            const auto v = top;
                            if (!visited[v]) {
                                visited[v] = true;
                                bfs.push(v);
                            }
                            setState(top, ni, nj, false);
                        }
                    }

                    setState(top, i, j, true);
                }
            }
        }
    }

    int ans = 0;
    for (auto el: visited) {
        if (el.second) ans++;
    }
    cout << ans << endl;
    return 0;
}