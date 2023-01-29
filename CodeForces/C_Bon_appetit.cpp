#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> G(N), T(M);
    for (int i = 0; i < N; i++) {
        cin >> G[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> T[i];
    }
    sort(T.rbegin(), T.rend());
    int ans = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    map<int, int> FRQ;
    for (int i = 0; i < N; i++) {
        FRQ[G[i]]++;
    }
    for (auto el: FRQ) {
        pq.push(el.second);
    }
    for (int i = 0; i < M; i++) {
        if (pq.empty()) break;
        auto biggest = pq.top();
        pq.pop();
        int take = min(T[i], biggest);
        ans += take;
        biggest -= take;
        if (take > 0) pq.push(biggest);
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