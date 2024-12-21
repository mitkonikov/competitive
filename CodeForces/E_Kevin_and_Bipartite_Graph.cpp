#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    if (M >= 2 * N) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> ans(2 * N, vector<int>(M, 0));
    if (M <= N) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2 * N; j++) {
                ans[j][i] = (i + 1);
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans[i][j] = (i + j) % N + 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j < N) {
                    ans[N + i][j] = i + 1;
                } else {
                    ans[N + i][j] = (i + 1 + j - N) % N + 1;
                }
            }
        }
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}