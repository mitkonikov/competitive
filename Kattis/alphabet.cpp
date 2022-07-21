#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> lcs(n + 1, vector<int>(27, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 26; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (s[i-1] - 'a' == j-1) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    cout << 26 - lcs[n][26] << endl;
    return 0;
}