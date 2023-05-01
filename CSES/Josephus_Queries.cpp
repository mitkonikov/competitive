#include <bits/stdc++.h>
#define ll long long

using namespace std;

int f(int N, int K) {
    if (N == 1) return 1;
    if (K <= (N + 1) / 2) {
        if (2 * K > N) return (2 * K) % N;
        else return 2 * K;
    }
    int ans = f(N / 2, K - (N + 1) / 2);
    if (N % 2 == 1) return 2 * ans + 1;
    return 2 * ans - 1;
}

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int N, K;
        cin >> N >> K;
        cout << f(N, K) << endl;
    }
    return 0;
}