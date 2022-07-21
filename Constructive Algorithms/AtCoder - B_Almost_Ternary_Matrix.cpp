#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        v[i][0] = (i % 2 == 0);
        for (int j = 1; j < m; j++) {
            v[i][j] = (((j-1) / 2) % 2) ^ (i % 2 != 0);
        }
    }

    for (int i = 2; i < n; i += 4) {
        swap(v[i], v[i+1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        } cout << endl;
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