#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<int> r(3), c(3);

int ans = 0;

void dfs(int x, int y) {
    if (x == 3) {
        for (int i = 0; i < 3; i++) {
            if (r[i] != 0 || c[i] != 0) {
                return;
            }
        }
        ans++;
        return;
    }

    if (y == 0 && x > 0 && r[x-1] != 0) return;

    int nx = x;
    int ny = y + 1;
    if (ny >= 3) {
        nx++;
        ny = 0;
    }

    int saveR = r[x];
    int saveC = c[y];
    int mm = min(r[x], c[y]);
    for (int i = 0; i < mm; i++) {
        r[x]--;
        c[y]--;
        dfs(nx, ny);
    }
    r[x] = saveR;
    c[y] = saveC;
}

int main() {
    for (int i = 0; i < 3; i++) cin >> r[i];
    for (int i = 0; i < 3; i++) cin >> c[i];
    dfs(0, 0);
    cout << ans << endl;
    cout << flush;
    return 0;
}