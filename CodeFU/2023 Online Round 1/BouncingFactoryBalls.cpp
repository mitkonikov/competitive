#include <bits/stdc++.h>

using namespace std;

class BouncingFactoryBalls {
   public:
    int numberOfBounces(int x, int y, int N, int M, string direction) {
        int dx[4] = {1, -1, -1, 1};
        int dy[4] = {1, 1, -1, -1};
        map<string, int> mp;
        mp["bottomRight"] = 0;
        mp["bottomLeft"] = 3;
        mp["topRight"] = 1;
        mp["topLeft"] = 2;
        int dir = mp[direction];
        vector<vector<int>> visited(N, vector<int>(M, 0));
        int nx = x;
        int ny = y;
        int b = 0;
        while (visited[nx][ny] < 10) {
            if (nx == N - 1 && ny == M - 1) {
                return b;
            }
            if ((nx == N - 1 && nx == 0) || (ny == M - 1 && nx == 0) || (nx == 0 && ny == 0)) {
                if (dir == 0) dir = 2;
                else if (dir == 1) dir = 3;
                else if (dir == 2) dir = 0;
                else if (dir == 3) dir = 1;
            }
            visited[nx][ny]++;
            int mx = nx + dx[dir];
            int my = ny + dy[dir];
            if (my >= M) {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 2;
                b++;
            } else if (my < 0) {
                if (dir == 3) dir = 0;
                else if (dir == 2) dir = 1;
                b++;
            } else if (mx >= N) {
                if (dir == 0) dir = 1;
                else if (dir == 3) dir = 2;
                b++;
            } else if (mx < 0) {
                if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                b++;
            }
            nx += dx[dir];
            ny += dy[dir];
        }
        return -1;
    }
};

int main() {
    BouncingFactoryBalls bf;
    cout << bf.numberOfBounces(1, 1, 4, 5, "bottomRight") << endl;
    return 0;
}