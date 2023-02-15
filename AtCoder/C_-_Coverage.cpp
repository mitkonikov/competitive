#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(M);
    for (int i = 0; i < M; i++) {
        int C;
        cin >> C;
        v[i].resize(C);
        for (int j = 0; j < C; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << M); i++) {
        set<int> s;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                for (auto el: v[j])
                    s.insert(el);
            }
        }
        ans += (s.size() == N);
    }
    cout << ans << endl;
    return 0;
}