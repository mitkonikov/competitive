#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
#define MX vector<vector<T>>
#define MOD 998244353
 
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
                    result.m[i][j] = (result.m[i][j] + (this->m[i][k] * b.m[k][j]) % MOD) % MOD;
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
    ll N, M;
    cin >> N >> M;
    vector<string> A(M);
    int mxl = 0;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        mxl = max(mxl, (int)A[i].size());
    }
    if (N <= mxl) {
        int ans_brute = 0;
        for (int i = 0; i < (1 << N); i++) {
            bool ok = 1;
            for (int s = 0; s < M && ok; s++) {
                if (A[s].size() > N) continue;
                for (int st = 0; st < (N - A[s].size() + 1); st++) {
                    bool match = 1;
                    for (int j = 0; j < A[s].size(); j++) {
                        match &= ((int)(A[s][j] - 'a') == (int)((i & (1 << (j+st))) > 0));
                    }
                    if (match) ok = 0;
                }
            }
            if (ok) ans_brute++;
        }
        cout << ans_brute << endl;
        return 0;
    }
    Matrix<ll> mat(126);
    vector<int> vec(126);
    for (int i = 0; i < (1 << mxl); i++) {
        bool ok = 1;
        for (int s = 0; s < M && ok; s++) {
            for (int st = 0; st < (mxl - A[s].size() + 1); st++) {
                bool match = 1;
                for (int j = 0; j < A[s].size(); j++) {
                    match &= (int)(A[s][j] - 'a') == (int)((i & (1 << (j+st))) > 0);
                }
                if (match) ok = 0;
            }
        }
        vec[i] = ok;
    }
    for (int i = 0; i < (1 << mxl); i++) {
        for (int j = 0; j < 2; j++) {
            int mask = ((i << 1) ^ j) & ((1 << mxl) - 1);
            mat.m[i][mask] = (vec[i] && vec[mask]);
        }
    }
    auto k = mat.binary(N - mxl);
    ll ans = 0;
    for (int i = 0; i < (1 << mxl); i++) {
        for (int j = 0; j < (1 << mxl); j++) {
            ans = (ans + k.m[i][j]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}