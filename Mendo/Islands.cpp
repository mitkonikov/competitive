// Task: https://mendo.mk/Task.do?id=52

#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
 
const int dx8[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy8[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<vector<bool>> mp(n + 2, vector<bool>(m + 2, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp[i+1][j+1] = (a[i][j] == 'x');
        }
    }
 
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
    n += 2;
    m += 2;
 
    struct pos {
        int x = -1, y = -1, id = -1;
        bool operator>(const pos& other) const {
            if (id == other.id) return (x > other.x);
            return (id > other.id);
        }
    };
 
    vector<pos> tree(n*m);
    vector<vector<int>> adj(n*m);
 
    auto is_valid = [&](int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    };
 
    auto edge_bfs = [&](int i, int j, int id, priority_queue<pos, vector<pos>, greater<pos>>& b) {
        queue<pair<int, int>> bfs;
        bfs.push({ i, j });
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = top.first + dx8[dir];
                int ny = top.second + dy8[dir];
                if (is_valid(nx, ny) && !visited[nx][ny] && mp[nx][ny]) {
                    visited[nx][ny] = true;
                    bfs.push({ nx, ny });
                    b.push({ nx, ny, id });
                }
            }
        }
    };
 
    priority_queue<pos, vector<pos>, greater<pos>> bfs;
    tree[0] = { 0, 0, 0 };
    bfs.push({ 0, 0, 0 });
    int id = 1;
    while (!bfs.empty()) {
        auto top = bfs.top();
        bfs.pop();
         
        for (int dir = 0; dir < 4; dir++) {
            int nx = top.x + dx[dir];
            int ny = top.y + dy[dir];
            if (is_valid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (mp[nx][ny]) {
                    tree[id] = { nx, ny, id };
                    edge_bfs(nx, ny, id, bfs);
                    adj[top.id].push_back(id);
                    bfs.push({ nx, ny, id });
                    id++;
                } else {
                    bfs.push({ nx, ny, top.id });
                }
            }
        }
    }
 
    vector<int> sz(n*m);
    auto dfs = [&](auto&& dfs, int u, int p) -> int {
        int size = 1;
        for (auto v: adj[u]) {
            if (v == p) continue;
            size = max(size, dfs(dfs, v, u) + 1);
        }
        return sz[u] = size;
    };
 
    dfs(dfs, 0, -1);
 
    vector<int> ans(n*m);
    for (int i = 0; i < n*m; i++) ans[sz[i]]++;
    while (!ans.empty() && ans.back() == 0) ans.pop_back();
    ans.pop_back();
 
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] == 0) break;
        cout << ans[i] << endl;
    }
 
    return 0;
}