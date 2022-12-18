#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> mat(N, vector<bool>(M, 0));
    int ones = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int b; cin >> b;
            mat[i][j] = (b == 1);
            if (mat[i][j]) ones++;
        }
    }
    if (ones % N != 0) {
        cout << -1 << endl;
        return;
    }
    ones /= N;
    vector<bool> OK(N, false);
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> pqs(M);
    vector<int> row_count(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j]) row_count[i]++;
        }
        if (row_count[i] == ones) {
            OK[i] = true;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (OK[i]) continue;
        if (row_count[i] >= ones) continue;
        for (int j = 0; j < M; j++) {
            if (!mat[i][j]) {
                pqs[j].push({ row_count[i], i });
            }
        }
    }
    struct sw {
        int row1, row2, col;
    };
    vector<sw> ans;
    for (int i = 0; i < N; i++) {
        if (OK[i]) continue;
        if (row_count[i] <= ones) continue;
        for (int j = 0; j < M; j++) {
            if (OK[i]) break;
            if (mat[i][j]) {
                // try here
                while (!pqs[j].empty()) {
                    auto top = pqs[j].top();
                    pqs[j].pop();
                    if (OK[top.second]) continue;
                    if (mat[top.second][j]) continue;
                    ans.push_back({ i, top.second, j });
                    mat[i][j] = 0;
                    row_count[i]--;
                    if (row_count[i] == ones) {
                        OK[i] = true;
                    }
                    mat[top.second][j] = 1;
                    row_count[top.second]++;
                    if (row_count[top.second] == ones) {
                        OK[top.second] = true;
                    }
                    break;
                }
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < N; i++) {
        ok &= (OK[i]);
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto el: ans) {
        cout << el.row1 + 1 << " " << el.row2 + 1 << " " << el.col + 1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}