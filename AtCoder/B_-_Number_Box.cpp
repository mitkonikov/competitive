#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int dir = 0; dir < 8; dir++) {
                ll cur = 0;
                int nx = i, ny = j;
                for (int k = 0; k < n; k++) {
                    cur *= 10;
                    cur += v[nx][ny] - '0';
                    nx = nx + dx[dir];
                    ny = ny + dy[dir];
                    nx = (nx + 3 * n) % n;
                    ny = (ny + 3 * n) % n;
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}