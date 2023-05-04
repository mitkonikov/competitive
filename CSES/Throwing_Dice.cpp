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

template<typename T>
void print(MX a) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> m(7, vector<ll>(7, 0));
    for (int i = 0; i < 6; i++) m[i][i+1] = 1;
    for (int i = 0; i < 6; i++) m[6][i+1] = 1;

    auto result = binary(m, n);
    cout << result[6][6] << endl;

    return 0;
}