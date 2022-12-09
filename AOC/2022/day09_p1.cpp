#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
int mp[256];

const int dx8[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy8[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

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
    int Hi = 0, Hj = 0;
    int Ti = 0, Tj = 0;
    char prev_dir = -1;
    set<pair<int, int>> pos;
    pos.insert({ 0, 0 });
    for (int i = 0; i < Q; i++) {
        char dir;
        int many;
        cin >> dir >> many;
        assert(dir != prev_dir);
        prev_dir = dir;
        for (int j = 0; j < many; j++) {
            Hi = Hi + dx[mp[dir]];
            Hj = Hj + dy[mp[dir]];
            if (not_touching(Hi, Hj, Ti, Tj)) {
                Ti = Hi - dx[mp[dir]];
                Tj = Hj - dy[mp[dir]];
                pos.insert({ Ti, Tj });
            }
        }
    }
    cout << pos.size() << endl;
    return 0;
}