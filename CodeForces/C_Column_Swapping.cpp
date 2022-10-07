#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> s(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            s[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(s[i].begin(), s[i].end());
    }

    map<int, bool> col_needed;
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        int cols = 0;
        for (int j = 0; j < m && ok; j++) {
            if (a[i][j] != s[i][j]) {
                cols++;
                col_needed[j] = true;
            }

            if (cols > 2) {
                ok = false; break;
            }
        }
    }

    if (!ok || col_needed.size() > 2) {
        cout << -1 << endl;
        return;
    }

    if (col_needed.size() == 0) {
        cout << 1 << " " << 1 << endl;
        return;
    }

    vector<int> sw;
    for (auto it: col_needed) {
        sw.push_back(it.first);
    }

    for (int i = 0; i < n; i++) {
        swap(a[i][sw[0]], a[i][sw[1]]);
        ok &= is_sorted(a[i].begin(), a[i].end());        
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    cout << sw[0] + 1 << " " << sw[1] + 1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}