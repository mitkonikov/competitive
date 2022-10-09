#include <bits/stdc++.h>

using namespace std;

int W, H;
vector<vector<bool>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> start;

template<typename T>
vector<vector<T>> rotate(const vector<vector<T>>& matrix, int x, int y) {
    vector<vector<T>> result(x, vector<T>(y));

    int newColumn, newRow = 0;
    for (int oldColumn = x - 1; oldColumn >= 0; oldColumn--) {
        newColumn = 0;
        for (int oldRow = 0; oldRow < y; oldRow++) {
            result[newRow][newColumn] = matrix[oldRow][oldColumn];
            newColumn++;
        }
        newRow++;
    }

    return result;
}

string component = "";

int rotation = 0;

const int dx[4] = {     0,  1 ,   0,  -1  };
const int dy[4] = {    -1,  0 ,   1,   0  };
const char dc[4] = {  'L', 'D', 'R', 'U'   };
const char dcr[4] = { 'R', 'U', 'L', 'D'   };
map<char, char> dr;

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

int startHit;

struct node {
    int x, y;
    char c;
};

void dfs(int x, int y, const int &h, const int &w) {
    stack<node> DFS;
    DFS.push({ x, y, 'x' });

    while (!DFS.empty()) {
        auto p = DFS.top();

        visited[p.x][p.y] = true;
        if (start[p.x][p.y] != -1) startHit = start[p.x][p.y];

        bool pushed = false;

        for (int k = 0; k < 4; k++) {
            int nk = (rotation+k) % 4;
            int nx = p.x + dx[nk];
            int ny = p.y + dy[nk];

            if (valid(nx, ny, h, w) && !visited[nx][ny] && matrix[nx][ny]) {
                component += dc[nk];
                DFS.push({ nx, ny, dc[nk] });
                pushed = true;
                break;
            }
        }

        if (!pushed) {
            component += dr[p.c];
            DFS.pop();
        }
    }
}

void clear() {
    for (int i = 0; i < 2010; i++) {
        for (int j = 0; j < 2010; j++) {
            visited[i][j] = false;
        }
    }
}

vector<vector<string>> mp;

void printMat(const vector<vector<bool>> &matrix, int th, int tw) {
    cout << endl;
    for (int i = 0; i < th; i++) {
        for (int j = 0; j < tw; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    dr['x'] = 'x';
    dr['L'] = 'R';
    dr['R'] = 'L';
    dr['D'] = 'U';
    dr['U'] = 'D';

    cin >> H >> W;

    matrix.resize(H, vector<bool>(W, false));
    start.resize(H, vector<int>(W, -1));
    visited.resize(2010, vector<bool>(2010, false));

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '1') matrix[i][j] = 1;
        }
    }

    int counter = 0;

    int th = H, tw = W;
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < th; x++) {
            for (int y = 0; y < tw; y++) {
                if (!visited[x][y] && matrix[x][y]) {
                    if (i == 0) start[x][y] = counter++;
                    
                    component = "x";
                    startHit = -1;

                    dfs(x, y, th, tw);

                    if (startHit < mp.size())
                        mp[startHit].push_back(component);
                    else
                        mp.push_back({ component });
                }
            }
        }

        swap(th, tw);
        matrix = rotate(matrix, th, tw);
        start = rotate(start, th, tw);
        clear();
    }

    set<string> s;

    for (auto it: mp) {
        sort(it.begin(), it.end());
        s.insert(it[0]);
    }

    cout << s.size() << endl;
    return 0;
}