#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; i++) cin >> s[i];
    auto bfs = [&](int sx, int sy) {
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({ sx, sy });
        visited[sx][sy] = true;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (s[top.first ^ 1][top.second] == 'B' && !visited[top.first ^ 1][top.second]) {
                visited[top.first ^ 1][top.second] = true;
                q.push({ top.first ^ 1, top.second });
            } else if (top.second + 1 < n && s[top.first][top.second + 1] == 'B') {
                visited[top.first][top.second + 1] = true;
                q.push({ top.first, top.second + 1 });
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'B' && !visited[i][j]) return false;
            }
        }
        return true;
    };
    if (s[0][0] == 'B') {
        if (bfs(0, 0)) {
            cout << "YES" << endl;
            return;
        }
    }
    if (s[1][0] == 'B') {
        if (bfs(1, 0)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}