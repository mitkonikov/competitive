#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mp[256];

const int dx8[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy8[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };
int op[8] = { 1, 0, 3, 2, 5, 4, 7, 6 };

inline bool not_touching(int i, int j, int x, int y) {
    if (i == x && j == y) return false;
    for (int dir = 0; dir < 8; dir++) {
        int ni = i + dx8[dir];
        int nj = j + dy8[dir];
        if (ni == x && nj == y) return false;
    }
    return true;
}

int main() {
    mp['L'] = 0;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    
    int Q;
    cin >> Q;
    char prev_dir = -1;
    set<pair<int, int>> pos;
    pos.insert({ 0, 0 });
    vector<pair<int, int>> ropes(10);
    auto print = [&]() {
        vector<vector<char>> mat(30, vector<char>(30, '.'));
        for (int i = 0; i < 10; i++) {
            mat[ropes[i].first + 15][ropes[i].second + 15] = (i == 0 ? 'H' : (char)(i + '0'));
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                cout << mat[i][j];
            } cout << endl;
        } cout << endl;
        cout << endl;
    };
    auto find_touching = [&](int X, int Y, int me) {
        for (int dir = 0; dir < 8; dir++) {
            int x = X + dx8[dir];
            int y = Y + dy8[dir];
            if (!not_touching(x, y, ropes[me].first, ropes[me].second)) {
                return dir;
            }
        }
        return -1;
    };
    for (int q = 0; q < Q; q++) {
        char dir;
        int many;
        cin >> dir >> many;
        assert(dir != prev_dir);
        prev_dir = dir;
        for (int j = 0; j < many; j++) {
            ropes[0].first = ropes[0].first + dx8[mp[dir]];
            ropes[0].second = ropes[0].second + dy8[mp[dir]];
            for (int i = 1; i < 10; i++) {
                if (not_touching(ropes[i-1].first, ropes[i-1].second, ropes[i].first, ropes[i].second)) {
                    auto p = find_touching(ropes[i-1].first, ropes[i-1].second, i);
                    assert(p != -1);
                    ropes[i].first = ropes[i-1].first + dx8[p];
                    ropes[i].second = ropes[i-1].second + dy8[p];
                }
            }
            pos.insert(ropes.back());
        }
    }
    cout << pos.size() << endl;
    return 0;
}