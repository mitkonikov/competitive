#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<set<int>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int count = 0;
            for (int k = 0; k < M; k++) {
                count += (A[i][k] != A[j][k]);
            }
            if (count == 1) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    do {
        bool ok = 1;
        for (int i = 1; i < N; i++) {
            ok &= (adj[order[i-1]].count(order[i]));
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << "No" << endl;
    return 0;
}