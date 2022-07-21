#include <bits/stdc++.h>
#define MX vector<vector<T>>
#define MOD 1000000007

using namespace std;

template<typename T>
void print(MX a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

template<typename T>
MX mult(MX a, MX b) {
    MX result(a.size(), vector<T>(a.size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> mat(n, vector<long long>(n, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        mat[a][b] = 1;
    }

    // print(mat);
    auto result = binary(mat, k);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = (sum + result[i][j]) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}