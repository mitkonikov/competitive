#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<pair<int, int>> p;
    vector<vector<int>> X(2 * N);
    for (int i = 0; i < N; i++) {
        if (A[i] > N) continue;
        int where = (A[i] + i + 1) % N;
        X[(A[i] - where + N) % N].push_back(i);
    }
    if (N == 1 && A[0] == 1) {
        cout << "Yes" << endl;
        return;
    }
    if (X[0].empty()) {
        assert(K >= 1);
        cout << "No" << endl;
        return;
    }
    if (K == 1) {
        cout << "Yes" << endl;
        return;
    }
    queue<pair<int, int>> q;
    for (auto u: X[0]) q.push({ A[u] % N, 1 });
    vector<int> visited(2 * N, 0);
    visited[0] = 1;
    while (!q.empty()) {
        auto [shift, dist] = q.front();
        q.pop();
        if (dist >= K) {
            cout << "Yes" << endl;
            return;
        }
        if (visited[shift]) {
            cout << "Yes" << endl;
            return;
        }

        visited[shift] = true;
        for (auto el: X[shift]) {
            q.push({ (shift + A[el]) % N, dist + 1 });
        }
    }
    cout << "No" << endl;
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