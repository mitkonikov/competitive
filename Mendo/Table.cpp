#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<vector<int>> t(3, vector<int>(N));
    vector<map<int, int>> frq(3);
    vector<map<int, vector<int>>> occ(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> t[i][j];
            frq[i][t[i][j]]++;
            occ[i][t[i][j]].push_back(j);
        }
    }
    queue<int> q;
    vector<bool> deleted(N, false);
    for (int i = 1; i <= N; i++) {
        int MN = INT_MAX;
        for (int j = 0; j < 3; j++) MN = min(MN, frq[j][i]);
        if (MN == 0) q.push(i);
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            for (auto x: occ[i][top]) { // x - col
                if (deleted[x]) continue;
                for (int ii = 0; ii < 3; ii++) {
                    if (i != ii) {
                        auto& f = frq[ii][t[ii][x]];
                        f--;
                        if (f == 0) {
                            q.push(t[ii][x]);
                        }
                    }
                }
                deleted[x] = true;
            }
            occ[i][top].clear();
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) ans += (deleted[i]);
    cout << ans << endl;
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