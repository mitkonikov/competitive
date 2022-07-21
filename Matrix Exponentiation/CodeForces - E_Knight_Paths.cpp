#include <bits/stdc++.h>
#define MX vector<vector<T>>
#define data unsigned int
#define MXLL vector<vector<data>>
// #define MOD 4294967296
#define MOD 1000000007
#define mxDim 64
 
using namespace std;
 
int dx[] = {-2, -1, 2, -1, 2, 1, -2, 1};
int dy[] = {-1, -2, -1, 2, 1, 2, 1, -2};
 
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
MX identity(int n) {
    MX result(n, vector<T>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1;
    return result;
}
 
void makeIdentity(MXLL &a, int n) {
    for (int i = 0; i < n; i++) a[i][i] = 1;
}
 
template<typename T>
inline MX emptyMatrix(int n) {
    MX result(n, vector<T>(n, 0));
    return result;
}
 
template<typename T>
void usum(MX &a, const MX &b) {
    for (int i = 0; i < mxDim; i++) {
        for (int j = 0; j < mxDim; j++) {
            a[i][j] = (a[i][j] + b[i][j]) % MOD;
        }
    }
}
 
template<typename T>
void add1(MX &a) {
    for (int i = 0; i < mxDim; i++) {
        a[i][i]++;
    }
}
 
map<int, MXLL> mp;
 
MXLL mult2D(const MXLL &a, const MXLL &b) {
    MXLL result(mxDim, vector<data>(mxDim, 0));
    for (int i = 0; i < mxDim; i++) {
        for (int j = 0; j < mxDim; j++) {
            for (int k = 0; k < mxDim; k++) {
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
 
    return result;
}
 
MXLL binary(MXLL a, long long n) {
    if (n == 1) return a;
 
    long long nInit = n; // remember n for later
 
    // search the cache
    auto it = mp.find(n);
    if (it != mp.end()) {
        return it->second;
    }
 
    MXLL result;
    if (n % 2 == 0) {
        result = mult2D(binary(a, n/2), binary(a, n/2));
    } else {
        result = mult2D(binary(a, n-1), a);
    }
 
    mp[n] = result;
    return result;
}
 
MXLL globalA;
MXLL binary2(long long n) {
    if (n == 1) return globalA;
    if (n % 2 == 0) {
        MXLL temp = binary(globalA, n/2);
        add1(temp);
        auto r = mult2D(temp, binary2(n/2));
        return r;
    } else {
        MXLL result = binary(globalA, n);
        usum(result, binary2(n-1));
        return result;
    }
}
 
inline bool check(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
 
inline int h(int x, int y) {
    return x*8+y;
}
 
MXLL startMatrix() {
    vector<vector<data>> result(mxDim, vector<data>(mxDim, 0));
 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int X = h(i, j);
            for (int k = 0; k < 8; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (check(nx, ny)) {
                    int Y = h(nx, ny);
                    result[X][Y] = 1;
                }
            }
        }
    }
 
    return result;
}
 
int main() {
    long long K;
    cin >> K;
 
    if (K == 0) {
        cout << 1 << endl;
        return 0;
    }
 
    globalA = startMatrix();
    auto result = binary2(K);
    
    long long sum = 0;
    for (int j = 0; j < mxDim; j++) {
        sum = (sum + result[0][j]) % MOD;
    }
 
    cout << sum + 1 << endl;
 
    return 0;
}