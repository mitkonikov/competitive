#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> mat(H, vector<int>(W, 0));
    set<int> s, s_init;
    map<int, int> frq, frq_init;
    auto erase = [&](int x) {
        frq[x]--;
        if (frq[x] == 0) {
            s.erase(x);
        }
    };
    auto add = [&](int x) {
        frq[x]++;
        if (frq[x] == 1) {
            s.insert(x);
        }
    };
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> mat[i][j];
            add(mat[i][j]);
        }
    }
    s_init = s;
    frq_init = frq;
    vector<vector<int>> ans(H-h+1, vector<int>(W-w+1, 0));
    int sz = ans[0].size();
    for (int i = 0; i < ans.size(); i++) {
        s = s_init;
        frq = frq_init;

        for (int si = 0; si < h; si++) {
            for (int j = 0; j < w; j++) {
                erase(mat[i+si][j]);
            }
        }
        ans[i][0] = s.size();
        
        for (int j = 1; j < sz; j++) {
            for (int k = 0; k < h; k++) {
                add(mat[i+k][j-1]);
                erase(mat[i+k][j+w-1]);
            }
            ans[i][j] = s.size();
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < sz; j++) {
            cout << ans[i][j] << " ";
        } cout << endl;
    }
    return 0;
}