#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define MX vector<vector<T>>

template<typename T>
class Matrix { // Only for NxN matrix
public:
    MX m;
    int n;
    Matrix(int n) {
        this->n = n;
        m.resize(n, vector<T>(n, 0));
    }

    Matrix(const MX &copy) {
        this->m = MX(copy);
        this->n = copy.size();
    }

    void print() const {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++) {
                cout << m[i][j] << " ";
            }

            cout << "\n";
        }
        cout << flush;
    }

    Matrix operator*(const Matrix &b) const {
        Matrix<T> result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.m[i][j] = result.m[i][j] + (this->m[i][k] * b.m[k][j]);
                }
            }
        }

        return result;
    }

    Matrix binary(long long power) const {
        Matrix<T> a(this->m);
        Matrix<T> result(n);
        for (int i = 0; i < n; i++) result.m[i][i] = 1;

        while (power > 0) {
            if (power % 2 == 1) {
                result = result * a;
                power--;
            }

            a = a * a;
            power /= 2;
        }

        return result;
    }
};

int main() {
    Matrix<ll> m(4);
    m.m[0][1] = 1;
    m.m[1][2] = 1;
    m.m[2][3] = 1;
    m.m[3][0] = -1;
    m.m[3][1] = 2;
    m.m[3][2] = -2;
    m.m[3][3] = 2;
    int X;
    cin >> X;
    vector<int> a = { 1, 2, 4, 8, 16, 22 };
    if (X < 6) {
        cout << a[X-1] << endl;
        return 0;
    }
    auto p = m.binary(X-5);
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += (ll)a[i+1] * p.m[3][i];
    }
    cout << ans << endl;
    return 0;
}