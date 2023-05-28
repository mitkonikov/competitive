#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, H;
    cin >> N >> H;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    struct BFS {
        int i, x, y;
        ll power;
    };
    queue<BFS> bfs;
    bfs.push({ 0, 2, 1, H });
    int ans = 0;
    while (!bfs.empty()) {
        auto [i, x, y, p] = bfs.front();
        bfs.pop();

        if (i == N) break;
        if (A[i] < p) {
            ans = max(ans, i + 1);
            bfs.push({ i + 1, x, y, p + A[i] / 2 });
        } else {
            if (x) bfs.push({ i, x - 1, y, p * 2 });
            if (y) bfs.push({ i, x, y - 1, p * 3 });
        }
    }
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