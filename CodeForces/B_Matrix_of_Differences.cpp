#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int now[2] = { 1, n * n };
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = now[f];
                if (f == 0) now[f]++;
                else now[f]--;
                f ^= 1;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                ans[i][j] = now[f];
                if (f == 0) now[f]++;
                else now[f]--;
                f ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
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