#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    map<int, bool> mp;
    vector<vector<int>> mat(3);
    for (int i = 0; i < 3; i++) {
        int N;
        cin >> N;
        mat[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < mat[0].size(); i++) {
        for (int j = 0; j < mat[1].size(); j++) {
            for (int k = 0; k < mat[2].size(); k++) {
                int sum = mat[0][i] + mat[1][j] + mat[2][k];
                mp[sum] = true;
            }
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        cout << (mp.count(X) ? "Yes" : "No") << endl;
    }
    return 0;
}