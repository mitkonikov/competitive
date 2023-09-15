#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> deg(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        deg[v]++;
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) {
            ans.push_back(i);
        }
    }
    if (ans.size() > 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans[0] + 1 << endl;
    return 0;
}