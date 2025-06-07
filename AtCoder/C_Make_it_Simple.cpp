#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<pair<int, int>, int> edges;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            ans++;
            continue;
        }
        if (edges.count({ u, v }) || edges.count({ v, u })) {
            ans++;
            continue;
        }
        edges[{ u, v }] = 1;
    }
    cout << ans << endl;
    return 0;
}