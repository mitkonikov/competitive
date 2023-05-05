#include <bits/stdc++.h>
#define ll long long
#define MX vector<vector<T>>
#define MOD 1000000007

using namespace std;

template<typename T>
MX mult(MX a, MX b) {
    int N = a.size();
    MX result(N, vector<T>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return result;
}

template<typename T>
MX binary(MX a, long long n) {
    MX result(a.size(), vector<T>(a.size(), 0));
    for (int i = 0; i < a.size(); i++) result[i][i] = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = mult(result, a);
            n--;
        }

        a = mult(a, a);
        n /= 2;
    }

    return result;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> mat(N, vector<ll>(N, 0));

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        mat[u][v] += 1;
    }

    auto result = binary(mat, K);
    cout << result[0][N - 1] << endl;
    return 0;
}