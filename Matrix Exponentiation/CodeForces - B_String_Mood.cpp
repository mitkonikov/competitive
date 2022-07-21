#include <bits/stdc++.h>
#define MX vector<vector<T>>
#define MOD 1000000007

using namespace std;

template<typename T>
MX mult(MX a, MX b) {
    MX result = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return result;
}

template<typename T>
MX binary(MX a, long long n) {
    MX result = {{1, 0}, {0, 1}};
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
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    long long n;
    cin >> n;

    vector<vector<long long>> m = {{19, 7}, {6, 20}};

    auto result = binary(m, n);
    cout << result[0][0] << endl;

    return 0;
}