#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<bool> visited(N);
    vector<vector<int>> rev(N);
    for (int i = 0; i < N; i++) {
        rev[A[i]].push_back(i);
    }
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        int t = i;
        while (!visited[t]) {
            visited[t] = true;
            t = A[t];
        }
        vector<int> cycle;
        int new_t = t;
        do {
            cycle.push_back(new_t);
            new_t = A[new_t];
        } while (new_t != t);
        auto dfs = [&](auto&& dfs, int u) -> int {
            visited[u] = true;
            int mx = 1;
            for (auto v : rev[u]) {
                mx += dfs(dfs, v);
            }
            return mx;
        };
        int C = cycle.size();
        for (int k = 0; k < C; k++) {
            for (auto v : rev[cycle[k]]) {
                if (v != cycle[(k-1+C)%C]) {
                    ans = max(ans, dfs(dfs, v) + 1);
                }
            }
        }
    }
    cout << ans + 1 << endl;
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