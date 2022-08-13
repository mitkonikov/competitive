#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> read() {
    int w, h;
    cin >> w >> h;
    vector<vector<int>> v(w, vector<int>(h));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> v[i][j];
        }
    }
    return v;
}

int main() {
    vector<vector<int>> a = read();
    vector<vector<int>> b = read();
    
    int HA = a.size(), WA = a[0].size();
    int HB = b.size(), WB = b[0].size();
    bool ok = false;
    for (int i = 0; i < (1 << HA) && !ok; i++) {
        for (int j = 0; j < (1 << WA) && !ok; j++) {
            int i_count = __builtin_popcount(i);
            int j_count = __builtin_popcount(j);
            if (HA - i_count == HB && WA - j_count == WB) {

                bool okk = true;
                for (int ib = 0, ia = -1; ib < HB; ib++) {
                    ia++;
                    while ((1 << ia) & i) ia++;
                    for (int jb = 0, ja = -1; jb < WB; jb++) {
                        ja++;
                        while ((1 << ja) & j) ja++;
                        if (a[ia][ja] != b[ib][jb]) {
                            okk = false;
                        }
                    }
                }

                if (okk) ok = true;
            }
        }
    }
    
    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}