#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    bool flip = false;
    if (N > M) {
        swap(N, M);
        flip = true;
    }
    vector<vector<bool>> mat(N, vector<bool>(M));
    for (int i = 0; i < (flip?M:N); i++) {
        string S;
        cin >> S;
        for (int j = 0; j < (flip?N:M); j++) {
            if (flip) mat[j][i] = (S[j] == '#');
            else mat[i][j] = (S[j] == '#');
        }
    }
    vector<vector<int>> pref(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        pref[i][0] = mat[i][0];
        for (int j = 1; j < M; j++) {
            pref[i][j] = pref[i][j-1] + mat[i][j];
        }
    }
    // N <= M
    ll ans = 0;
    vector<int> mp(N * M * 4 + 100);
    const int off = N * M;
    for (int s = 0; s < N; s++) {
        vector<int> C(M);
        for (int t = s; t < N; t++) {
            for (int i = 0; i < M; i++) {
                C[i] += pref[t][i];
            }
            vector<int> remove(M);
            const int a = t - s + 1;
            for (int l = M - 1; l >= 0; l--) {
                const ll p = 2 * C[l] - a * l;
                const ll q = - a * l + a + 2 * (l>0?C[l-1]:0);
                mp[off+p]++;
                remove[l] = off+p;
                ans += mp[off+q];
            }
            for (int i = 0; i < M; i++) mp[remove[i]]--;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}