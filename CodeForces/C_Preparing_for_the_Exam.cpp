#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    vector<int> Q(K);
    for (int i = 0; i < K; i++) cin >> Q[i];
    if (K == N) {
        for (int i = 0; i < M; i++) cout << '1';
        cout << endl;
        return;
    }
    if (K < N - 1) {
        for (int i = 0; i < M; i++) cout << '0';
        cout << endl;
        return;
    }
    vector<bool> visited(M);
    for (int i = 0; i < K; i++) {
        visited[Q[i]-1] = true;
    }
    int cant = -1;
    for (int i = 0; i < M; i++) {
        if (!visited[i]) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
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