#include <bits/stdc++.h>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    
    int count = 0;

    auto valid = [&](int i, int j) {
        return (i >= 0 && i < H && j >= 0 && j < W);
    };

    vector<vector<int>> canvas(H, vector<int>(W, 0));
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // a, c - width
        // b, d - height

        a = min(a, W + 1);
        a = max(a, 0);
        b = min(b, H + 1);
        b = max(b, 0);
        c = min(c, W + 1);
        c = max(c, 0);
        d = min(d, H + 1);
        d = max(d, 0);

        swap(a, b);
        swap(c, d);

        vector<pair<int, int>> points;
        points.push_back({ a, b });
        points.push_back({ c, d });
        points.push_back({ a, d });
        points.push_back({ c, b });
        sort(points.begin(), points.end());
        
        bool ok = false;
        for (int x = points[0].first; x <= points[3].first; x++) {
            for (int y = points[0].second; y <= points[3].second; y++) {
                if (valid(x-1, y-1)) {
                    canvas[x-1][y-1]++;
                    ok = true;
                }
            }
        }

        if (ok) count++;
    }

    vector<vector<char>> ans(H + 2, vector<char>(W + 2, '-'));
    ans[0][0] = ans[H+1][0] = ans[0][W+1] = ans[H+1][W+1] = '+';
    for (int i = 1; i < H+1; i++) ans[i][0] = '|';
    for (int i = 1; i < H+1; i++) ans[i][W+1] = '|';

    string def = " .:-=+*$#%@";

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans[i+1][j+1] = def[min(canvas[i][j], (int)def.size() - 1)];
        }
    }

    for (int i = 0; i < H+2; i++) {
        for (int j = 0; j < W+2; j++) {
            cout << ans[i][j];
        } cout << endl;
    }

    cout << count;
    cout << " pravokotnikov na belem" << endl;

    return 0;
}