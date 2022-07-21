#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxH = 501, mxW = 501;

const int dx[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

inline bool valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void printMat(int mat[mxH][mxW]) {
    const int margin = 50;
    for (int i = mxH/2 - margin; i < mxH/2 + margin; i++) {
        for (int j = mxW/2 - margin; j < mxW/2 + margin; j++) {
            cout << ((mat[i][j] != -1) ? to_string(mat[i][j]) : ".") << " ";
        }
        cout << endl;
    }
}

#define MX vector<vector<T>>
#define MOD 1000000007

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    int mat[mxH][mxW];
    memset(mat, -1, sizeof(int)*mxH*mxW);

    int prefixRow[mxH];
    int prefixCol[mxW];
    memset(prefixRow, 0, sizeof(int)*mxH);
    memset(prefixCol, 0, sizeof(int)*mxW);

    queue<pair<int, int>> bfs;

    int offsetHeight = (mxH/2) - (h/2);
    int offsetWidth = (mxW/2) - (w/2);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char ch; cin >> ch;

            if (ch == '#') {
                int nx = offsetHeight + i, ny = offsetWidth + j;
                mat[nx][ny] = 0;
                bfs.push({ nx, ny });

                prefixRow[nx]++;
                prefixCol[ny]++;
            }
        }
    }

    auto diff = [&]() {
        int count = 0;
        for (int i = 0; i < mxH; i++) count += prefixRow[i];
        return count;
    };

    ll finalWidth = 1;
    ll finalHeight = 1;
    int used = 0;
    int maxTime = 1;
    ll prev = 0, pprev = 0, lastToPrev = 0;
    bool hitOnce = false;

    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        int time = mat[top.first][top.second];

        if (time > 0) {
            prefixRow[top.first]++;
            prefixCol[top.second]++;
        }
        
        if (time == k) {
            used = time;
            continue;
        }
        
        // we only want to check if the next element in the queue
        // is different to the current
        bool check = bfs.empty();
        if (!check) {
            auto nextElement = mat[bfs.front().first][bfs.front().second];
            check = (nextElement != time);
        }
        
        if (check) {
            ll d = diff();
            ll diffOfDiff = (d - prev) - pprev;
            if (prev != 0 && pprev != 0 && diffOfDiff == 8) {
                used = time;
                if (!hitOnce) {
                    lastToPrev = prev;
                    hitOnce = true;
                } else break;
            }

            // cout << d << " " << diffOfDiff << endl;
            pprev = d-prev;
            prev = d;
        }

        for (int i = 0; i < 8; i++) {
            int nx = top.first + dx[i];
            int ny = top.second + dy[i];

            if (valid(nx, ny, mxH, mxW) && mat[nx][ny] == -1) {
                mat[nx][ny] = time + 1;
                maxTime = max(maxTime, time+1);
                bfs.push({ nx, ny });
            }
        }
    }

    if (bfs.empty()) maxTime++;

    ll count = 0;
    for (int i = 0; i < mxH; i++) {
        for (int j = 0; j < mxW; j++) {
            if (mat[i][j] != -1 && mat[i][j] < maxTime) count++;
        }
    }

    // printMat(mat);

    ll rem = k - used;
    if (rem > 0 && count > 0) {
        ll c1 = lastToPrev;
        ll c2 = prev - lastToPrev - 8;
        rem += 2;
        count = rem * (c2 + 4LL * rem + 4) + c1;
    }
    
    cout << count << endl;

    return 0;
}