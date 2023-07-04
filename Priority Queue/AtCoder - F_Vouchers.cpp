#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    ll sum = 0;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        sum += P[i];
    }
    sort(P.begin(), P.end());
    vector<int> L(M), D(M);
    for (int i = 0; i < M; i++) cin >> L[i];
    for (int i = 0; i < M; i++) cin >> D[i];
    vector<vector<int>> events(N);
    for (int i = 0; i < M; i++) {
        int id = lower_bound(P.begin(), P.end(), L[i]) - P.begin();
        events[id].push_back(D[i]);
    }
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        for (int event: events[i]) pq.push(event);
        if (pq.empty()) continue;
        sum -= pq.top();
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}