#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> P(N, vector<int>(N, 0));
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> P[i][j];
            A[i][j] = P[i][j];
        }
    }
    vector<vector<int>> row(3, vector<int>(N));
    vector<vector<int>> col(3, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c = P[i][j];
            if (c == 0) continue;
            row[c][i]++;
            col[c][j]++;
        }
    }
    struct Event {
        int what, id, color;
    };
    queue<Event> bfs;
    vector<bool> prow(N), pcol(N);
    for (int c = 1; c < 3; c++) {
        for (int i = 0; i < N; i++) {
            if (row[c][i] == N) {
                bfs.push({ 0, i, c });
                prow[i] = true;
            }
            if (col[c][i] == N) {
                bfs.push({ 1, i, c });
                pcol[i] = true;
            }
        }
    }
    vector<Event> ans;
    while (!bfs.empty()) {
        auto [pos, id, color] = bfs.front();
        bfs.pop();
        ans.push_back({ pos, id, color });
        if (pos == 0) {
            prow[id] = true;
            for (int cl = 0; cl < N; cl++) {
                A[id][cl] = 0;
                col[0][cl]++;
                col[color][cl]--;
                if (!pcol[cl]) {
                    if (col[0][cl] + col[1][cl] == N) {
                        bfs.push({ 1, cl, 1 });
                        pcol[cl] = true;
                    } else if (col[0][cl] + col[2][cl] == N) {
                        bfs.push({ 1, cl, 2 });
                        pcol[cl] = true;
                    }
                }
            }
        } else {
            pcol[id] = true;
            for (int cl = 0; cl < N; cl++) {
                A[cl][id] = 0;
                row[0][cl]++;
                row[color][cl]--;
                if (!prow[cl]) {
                    if (row[0][cl] + row[1][cl] == N) {
                        bfs.push({ 0, cl, 1 });
                        prow[cl] = true;
                    } else if (row[0][cl] + row[2][cl] == N) {
                        bfs.push({ 0, cl, 2 });
                        prow[cl] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [what, id, color] : ans) {
        cout << what + 1 << " " << id + 1 << " " << color << endl;
    }
    return 0;
}