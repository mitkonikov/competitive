#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    int prevX = INT_MAX, prevY = INT_MAX;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R' && prevX == INT_MAX) {
                prevX = i;
                prevY = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                if (i < prevX || j < prevY) {
                    cout << "NO" << endl;
                    return;
                }
            } 
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}