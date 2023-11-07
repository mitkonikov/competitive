#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline void eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int R, S;
    cin >> R >> S;
    vector<vector<int>> ans(N - R + 1, vector<int>(M - S + 1));
    multiset<int> ms;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            ms.insert(A[i][j]);
        }
    }
    ans[0][0] = *prev(ms.end());
    for (int i = 0; i < N - R + 1; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < M - S; j++) {
                for (int l = i; l < i + R; l++) {
                    eraseOne(ms, A[l][j]);
                    ms.insert(A[l][j+S]);
                }
                // take the answer
                ans[i][j+1] = *prev(ms.end());
            }
            if (i + R >= N) break;
            for (int j = M - S; j < M; j++) {
                eraseOne(ms, A[i][j]);
                ms.insert(A[i + R][j]);
            }
            ans[i+1][M-S] = *prev(ms.end());
        }
        else {
            for (int j = M - 1; j - S >= 0; j--) {
                for (int l = i; l < i + R; l++) {
                    eraseOne(ms, A[l][j]);
                    ms.insert(A[l][j - S]);
                }
                ans[i][j-S] = *prev(ms.end());
            }
            if (i + R >= N) break;
            for (int j = 0; j < R; j++) {
                eraseOne(ms, A[i][j]);
                ms.insert(A[i + R][j]);
            }
            ans[i+1][0] = *prev(ms.end());
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}