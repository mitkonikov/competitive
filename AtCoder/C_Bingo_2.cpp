#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<set<int>> rows(N), cols(N), diag(2);
    for (int q = 0; q < T; q++) {
        int X;
        cin >> X;
        X--;
        int row = X / N;
        int col = X % N;
        rows[row].insert(col);
        cols[col].insert(row);
        if (row == col) {
            diag[0].insert(row);
        }
        if (col == N - row - 1) {
            diag[1].insert(col);
        }
        if (rows[row].size() == N || cols[col].size() == N || diag[0].size() == N || diag[1].size() == N) {
            cout << q + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}