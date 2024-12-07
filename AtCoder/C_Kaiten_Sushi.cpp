#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    const int MX = 2e5 + 100;
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    vector<int> cookie_eater(MX, 1e9);
    for (int i = 0; i < N; i++) {
        cookie_eater[A[i]] = min(cookie_eater[A[i]], i);
    }
    for (int i = 1; i < MX; i++) {
        cookie_eater[i] = min(cookie_eater[i], cookie_eater[i-1]);
    }
    for (int i = 0; i < M; i++) {
        if (cookie_eater[B[i]] == 1e9) cout << -1 << endl;
        else cout << cookie_eater[B[i]] + 1 << endl;
    }
    return 0;
}