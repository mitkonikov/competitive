#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;

#define ll long long
#define MX vector<vector<T>>
#define MOD 1000000007

template <typename T>
class Matrix {  // Only for NxN matrix
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
                    result.m[i][j] = ((ll)result.m[i][j] +
                                      ((ll)this->m[i][k] * b.m[k][j]) % MOD) %
                                     MOD;
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

class MazeWanderer {
   public:
    int solveMaze(int n, int a, int b, int c, string h) {
        Matrix<int> mat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i + 1;
                int y = j + 1;
                if (x >= y) continue;
                if (((ll)a * x + (ll)b * y) % c < c / 2) {
                    mat.m[i][j] = 1;
                    mat.m[j][i] = 1;
                }
            }
        }
        auto k = mat.binary(stoll(h));
        return k.m[0][n - 1];
    }
};

int main() {
    MazeWanderer w;
    cout << w.solveMaze(5, 5, 4, 11, "3") << endl;
    cout << w.solveMaze(99, 7844, 844, 5437, "1000000000000000") << endl;
    cout << w.solveMaze(10, 92, 89, 359, "11") << endl;
    return 0;
}