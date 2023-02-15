#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, C;
    cin >> N >> C;
    vector<ll> A(N);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pq.push({ i + 1 + A[i], i });
    }
    int ans = 0;
    vector<bool> visited(N, false);
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (visited[top.second]) continue;
        if (top.first > C) {
            break;
        }
        visited[top.second] = true;
        C -= top.first;
        ans++;
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