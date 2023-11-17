#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> mx(N);
    for (int i = 0; i < N; i++) {
        cin >> mx[i];
        mx[i]--;
    }
    ll DURATION;
    cin >> DURATION;
 
    vector<int> R(N), G(N);
    vector<vector<int>> P(11);
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> G[i];
        P[R[i]+G[i]].push_back(i);
    }
 
    vector<vector<priority_queue<int, vector<int>, greater<int>>>> pq(11);
    for (int i = 2; i <= 10; i++) {
        pq[i].resize(i);
        for (auto id: P[i]) {
            for (int k = R[id], count = 0; count < G[id]; k++, count++) {
                pq[i][k%i].push(id);
            }
        }
    }
 
    vector<int> state(N, 0);
    int count_ok = 0;
    ll time = 0;
 
    while (true) {
        int best_next_dim = -1;
        ll next_time = LLONG_MAX;
        for (int p = 2; p <= 10; p++) {
            int cur = time % p;
            for (int j = 0; j <= p; j++) {
                auto& pqq = pq[p][(cur + j) % p];
                while (!pqq.empty() && state[pqq.top()] == mx[pqq.top()]) {
                    pqq.pop();
                }
                if (!pqq.empty()) {
                    if (next_time == time + j && pqq.top() < best_next_dim) {
                        best_next_dim = pqq.top();
                    } else if (next_time > time + j) {
                        next_time = time + j;
                        best_next_dim = pqq.top();
                    }
                }
            }
        }
 
        if (best_next_dim == -1) {
            break;
        }
 
        state[best_next_dim]++;
        if (state[best_next_dim] == mx[best_next_dim]) count_ok++;
        time = next_time + DURATION;
        if (count_ok == N) break;
    }
    
    cout << time << endl;
    return 0;
}