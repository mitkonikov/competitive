#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct coord {
    int x = 0, y = 0, z = 0;
    void read() {
        cin >> x >> y >> z;
    }
    bool operator<(const coord& other) const {
        if (x == other.x) return (make_pair(y, z) < make_pair(other.y, other.z));
        return (x < other.x);
    }
    void umin(coord& a) {
        x = min(x, a.x);
        y = min(y, a.y);
        z = min(z, a.z);
    }
    void umax(coord& a) {
        x = max(x, a.x);
        y = max(y, a.y);
        z = max(z, a.z);
    }
    void dec() {
        x--; y--; z--;
    }
    void inc() {
        x++; y++; z++;
    }
    bool inside(coord& mn, coord& mx) {
        bool ok = true;
        ok &= (x >= mn.x && x <= mx.x); 
        ok &= (y >= mn.y && y <= mx.y); 
        ok &= (z >= mn.z && z <= mx.z);
        return ok; 
    }
    void print() {
        cout << x << " " << y << " " << z << endl;
    }
};

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main() {
    int N;
    cin >> N;
    vector<coord> coords(N);
    map<coord, bool> visited;
    map<coord, int> mp;
    coord bb_min, bb_max;
    for (int i = 0; i < N; i++) {
        coords[i].read();
        mp[coords[i]] = i;
        bb_min.umin(coords[i]);
        bb_max.umax(coords[i]);
    }
    bb_min.dec();
    bb_max.inc();
    int ans = 0;
    queue<coord> bfs;
    bfs.push(bb_min);
    visited[bb_min] = true;
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = top.x + dx[dir];
            int ny = top.y + dy[dir];
            int nz = top.z + dz[dir];
            coord nc = { nx, ny, nz };
            auto it = mp.find(nc);
            if (it != mp.end()) {
                ans++;
            } else {
                if (nc.inside(bb_min, bb_max) && !visited[nc]) {
                    visited[nc] = true;
                    bfs.push(nc);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}