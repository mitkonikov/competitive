#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int>> inside;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> outside;
    vector<ll> ans(N);
    for (int i = 0; i < N; i++) inside.push(i);
    int time = 0;
    for (int i = 0; i < M; i++) {
        int T, W, S;
        cin >> T >> W >> S;
        while (!outside.empty() && outside.top().first <= T) {
            auto t = outside.top();
            outside.pop();
            inside.push(t.second);
        }
        if (inside.empty()) continue;
        auto t = inside.top();
        ans[t] += W;
        inside.pop();
        outside.push({ T + S, t });
    }
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
    return 0;
}