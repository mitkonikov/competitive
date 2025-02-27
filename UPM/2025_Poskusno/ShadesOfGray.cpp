#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int W, H;
    cin >> W >> H;
    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            double blue = ((1 << 8) - 1) & A[i][j];
            double green = ((((1 << 8) - 1) << 8) & A[i][j]) >> 8;
            double red = ((((1 << 8) - 1) << 16) & A[i][j]) >> 16;
            double g = blue * 0.11 + green * 0.59 + red * 0.3;
            A[i][j] = round(g);
        }
    }
    cout << W << " " << H << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}