#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main() {
    int n;
    cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    int m = mat[0].size();
    auto valid = [&](int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    };
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool vis = false;
            for (int dir = 0; dir < 4; dir++) {
                bool ok = true;
                int du = i + dx[dir];
                int dv = j + dy[dir];
                int me = mat[i][j];
                while (valid(du, dv)) {
                    if (mat[du][dv] >= me) {
                        ok = false;
                        break;
                    }
                    du = du + dx[dir];
                    dv = dv + dy[dir];
                }
                if (ok) {
                    vis = true;
                    break;
                }
            }
            if (vis) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}