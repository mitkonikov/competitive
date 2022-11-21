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

struct Cell {
    int id;
    int x, y;
    int year;
    bool colored = false;

    bool operator<(const Cell &other) {
        return year > other.year;
    }

    bool operator<(const Cell* &other) {
        return year > other->year;
    }
};

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int q;
    cin >> q;

    vector<int> qs(q);
    for (int i = 0; i < q; i++) cin >> qs[i];
    reverse(qs.begin(), qs.end());
    
    int r, c; cin >> r >> c;
    vector<vector<Cell>> mat(r, vector<Cell>(c));

    vector<Cell*> sorted_cells(r * c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j].year;
            mat[i][j].x = i;
            mat[i][j].y = j;
            mat[i][j].id = i * c + j;

            sorted_cells[i * c + j] = &mat[i][j];
        }
    }

    sort(sorted_cells.begin(), sorted_cells.end(), [](const Cell* a, const Cell* b) {
        return a->year > b->year;
    });
    
    dsu d(r * c);

    int sets = 0;
    int pointer = 0;

    vector<int> ans(q+1);

    for (int i = 0; i < q; i++) {
        int year = qs[i];

        if (year > sorted_cells[pointer]->year) {
            ans[q-i] = ans[q-i+1];
            continue;
        }

        while (pointer < sorted_cells.size() && sorted_cells[pointer]->year > year) {
            sorted_cells[pointer]->colored = true;

            set<pair<int, int>> colored_adj;
            set<int> which_set;

            for (int k = 0; k < 4; k++) {
                int nx = sorted_cells[pointer]->x + dx[k];
                int ny = sorted_cells[pointer]->y + dy[k];
                if (valid(nx, ny, r, c)) {
                    bool colored = mat[nx][ny].colored;
                    if (colored) {
                        colored_adj.insert({ nx, ny });
                        which_set.insert(d.find_set(mat[nx][ny].id));
                        continue;
                    }
                }
            }

            for (auto it = colored_adj.begin(); it != colored_adj.end(); it++) {
                auto p = *it;
                mat[p.first][p.second].colored = true;

                int id = mat[p.first][p.second].id;
                d.merge(sorted_cells[pointer]->id, id);
            }

            sets -= which_set.size() - 1;
            pointer++;
        }

        ans[q - i] = sets;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}