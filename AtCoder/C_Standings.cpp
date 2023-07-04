#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        // A[a] / (A[a] + B[a]) > A[b] / (A[b] + B[b])
        // A[a] * (A[b] + B[b]) > A[b] * (A[a] + B[a])
        if (A[a] * (A[b] + B[b]) == A[b] * (A[a] + B[a])) return a < b;
        return A[a] * (A[b] + B[b]) > A[b] * (A[a] + B[a]);
    });
    for (auto el: order) cout << el + 1 << " ";
    cout << endl;
    return 0;
}