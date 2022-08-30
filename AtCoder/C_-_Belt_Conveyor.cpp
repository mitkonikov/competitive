#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int i = 0, j = 0;
    while (true) {
        if (visited[i][j]) {
            cout << -1 << endl;
            return 0;
        }

        visited[i][j] = true;
        int ai = i, aj = j;
        if (mat[i][j] == 'R') {
            j++;
        } else if (mat[i][j] == 'L') {
            j--;
        } else if (mat[i][j] == 'U') {
            i--;
        } else if (mat[i][j] == 'D') {
            i++;
        }

        if (i >= 0 && j >= 0 && i < n && j < m) {
            continue;
        } else {
            cout << ai+1 << " " << aj+1 << endl;
            break;
        }
    }
    cout << flush;
    return 0;
}