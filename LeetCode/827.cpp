#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n, -1);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    int merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int dx[4] = { 0, 0, 1, -1 };
        const int dy[4] = { 1, -1, 0, 0 };
        const int N = grid.size();
        dsu DSU(N * N);
        auto from_coord = [&](int x, int y) {
            return x * N + y;
        };
        auto to_coord = [&](int coord) {
            return vector<int>{ coord / N, coord % N };
        };
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0) continue;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                        if (grid[nx][ny] == 1) {
                            DSU.merge(from_coord(i, j), from_coord(nx, ny));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N * N; i++) {
            ans = max(ans, DSU.size(i));
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) continue;
                set<int> neigh;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                        if (grid[nx][ny] == 1) {
                            neigh.insert(DSU.find_set(from_coord(nx, ny)));
                        }
                    }
                }
                int new_sum = 1;
                for (auto el: neigh) {
                    new_sum += DSU.size(el);
                }
                ans = max(ans, new_sum);
            }
        }
        return ans;
    }
};