#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int A[2001][2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int count = 0;
            for (int k = 0; k < M; k++) {
                if (A[i][k] == A[j][k]) count++;
            }
            ans += ((count & 1) > 0);
        }
    }
    cout << ans << endl;
    return 0;
}