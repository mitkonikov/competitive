#include <bits/stdc++.h>
#define ll long long
#define MX vector<vector<T>>
#define MXLL vector<vector<long long>>
#define INF LLONG_MAX
#define MOD 1000000007

using namespace std;

template<typename T>
void print(MX a) {
    int N = a.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == INF) cout << "INF ";
            else cout << a[i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
}

template<typename T>
MX mult(MX a, MX b) {
    int N = a.size();
    MX result(N, vector<T>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T minPath = INF;
            for (int k = 0; k < N; k++) {
                if (a[i][k] != INF && b[k][j] != INF)
                    minPath = min(minPath, (a[i][k]+b[k][j]));
            }
            
            if (minPath != INF) {
                if (result[i][j] == INF) result[i][j] = minPath;
                else result[i][j] = (result[i][j] + minPath);
            }
        }
    }

    return result;
}

map<long long, MXLL> mp;

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
        result = mult(binary(a, n/2), binary(a, n/2));
    } else {
        result = mult(binary(a, n-1), a);
    }

    mp[n] = result;
    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> mat(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;

        mat[a][b] = min(mat[a][b], w);
    }

    mat = binary(mat, k);

    ll minPath = mat[0][n - 1];
    if (minPath == INF) cout << -1 << endl;
    else cout << minPath << endl;
    return 0;
}