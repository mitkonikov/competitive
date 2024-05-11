#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> T(M + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] >= N) continue;
        int L = (A[i] >= 0 ? 1 : (-A[i] + i) / (i + 1));
        int R = min(M + 1, (N - A[i] + i) / (i + 1));
        for (int j = L; j < R; j++) T[j].push_back(A[i] + (i + 1) * j);
    }
    for (int i = 1; i <= M; i++) {
        int mx = T[i].size();
        vector<bool> exists(mx + 1);
        for (auto value: T[i]) {
            if (value < mx) exists[value] = true;
        }
        int ans = 0;
        while (exists[ans]) ans++;
        cout << ans << endl;
    }
    return 0;
}