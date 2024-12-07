#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> mat(H);
    for (int i = 0; i < H; i++) cin >> mat[i];
    int ans = 0;
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (mat[x][y] == '#') continue;
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    if (mat[k][l] == '#') continue;
                    int hum = 0;
                    for (int i = 0; i < H; i++) {
                        for (int j = 0; j < W; j++) {
                            if (mat[i][j] == '.' && (abs(i-x)+abs(j-y) <= D || abs(i-k)+abs(j-l)<=D)) {
                                hum++;
                            }
                        }
                    }
                    ans = max(ans, hum);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}