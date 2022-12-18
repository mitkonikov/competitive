#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct coord {
    int x, y, z;
    void read() {
        cin >> x >> y >> z;
    }
    bool operator<(const coord& other) const {
        if (x == other.x) return (make_pair(y, z) < make_pair(other.y, other.z));
        return (x < other.x);
    }
};

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    int N;
    cin >> N;
    vector<coord> coords(N);
    map<coord, int> mp;
    for (int i = 0; i < N; i++) {
        coords[i].read();
        mp[coords[i]] = i;
    }
    assert(mp.size() == N);
    int ans = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        queue<coord> bfs;
        bfs.push(coords[i]);
        visited[i] = true;
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            ans += 6;
            for (int dir = 0; dir < 6; dir++) {
                int nx = top.x + dx[dir];
                int ny = top.y + dy[dir];
                int nz = top.z + dz[dir];
                auto it = mp.find({ nx, ny, nz });
                if (it != mp.end()) {
                    ans--;
                    if (!visited[it->second]) {
                        visited[it->second] = true;
                        bfs.push(coords[it->second]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}