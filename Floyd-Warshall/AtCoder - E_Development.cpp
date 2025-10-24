#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    N += 2;
    vector<vector<ll>> mat(N, vector<ll>(N, 1e18));
    for (int i = 0; i < N; i++) mat[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        mat[A][B] = min(mat[A][B], (ll)C);
        mat[B][A] = min(mat[B][A], (ll)C);
    }
    int K, T;
    cin >> K >> T;
    mat[N-2][N-1] = T;
    vector<int> Ds(K);
    for (int i = 0; i < K; i++) {
        cin >> Ds[i];
        Ds[i]--;
        mat[Ds[i]][N-2] = min(mat[Ds[i]][N-2], (ll)0);
        mat[N-1][Ds[i]] = min(mat[N-1][Ds[i]], (ll)0);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = min(mat[i][j], (ll)mat[i][k] + mat[k][j]);
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < N - 2; j++) {
            if (mat[i][j] == 1e18) continue;
            sum += mat[i][j];
        }
    }
    auto update = [&](int i, int j, ll new_value) {
        if (mat[i][j] == 1e18) {
            if (new_value < 1e18) {
                if (i < N - 2 && j < N - 2) {
                    sum += new_value;
                }
                mat[i][j] = new_value;
            }
        } else {
            if (new_value < mat[i][j]) {
                if (i < N - 2 && j < N - 2) {
                    sum -= mat[i][j];
                    sum += new_value;
                }
                mat[i][j] = new_value;
            }
        }
    };
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int X, Y, T;
            cin >> X >> Y >> T;
            X--; Y--;
            update(X, Y, T);
            update(Y, X, T);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    update(i, j, mat[i][X] + mat[X][Y] + mat[Y][j]);
                    update(i, j, mat[i][Y] + mat[Y][X] + mat[X][j]);
                }
            }
        } else if (t == 2) {
            int X;
            cin >> X;
            X--;
            mat[X][N-2] = min(mat[X][N-2], (ll)0);
            mat[N-1][X] = min(mat[N-1][X], (ll)0);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    update(i, j, mat[i][X] + mat[X][N-2] + mat[N-2][j]);
                    update(i, j, mat[i][N-1] + mat[N-1][X] + mat[X][j]);
                }
            }
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}