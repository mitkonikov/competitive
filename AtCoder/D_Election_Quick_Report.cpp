#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> votes(N);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < M; i++) {
        int C;
        cin >> C;
        C--;
        votes[C]++;
        pq.push({ votes[C], -C });
        auto [votes, c] = pq.top();
        cout << -c + 1 << endl;
    }
    return 0;
}