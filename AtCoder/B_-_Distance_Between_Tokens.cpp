#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'o') {
                if (x == -1) {
                    x = i;
                    y = j;
                } else {
                    cout << abs(i - x) + abs(j - y) << endl;
                    return 0;
                }
            }
        }
    }
    cout << flush;
    return 0;
}