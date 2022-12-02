// Task: https://mendo.mk/Task.do?id=287

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> mem(k, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        mem[i%k][s[i]-'A']++;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int mx_id = -1;
        int mx = 0;
        for (int c = 0; c < 26; c++) {
            if (mem[i][c] > mx) {
                mx = mem[i][c];
                mx_id = c;
            }
        }
        for (int c = 0; c < 26; c++) {
            if (c != mx_id) {
                ans += mem[i][c];
            }
        }
    }
    cout << ans << endl;
    return 0;
}