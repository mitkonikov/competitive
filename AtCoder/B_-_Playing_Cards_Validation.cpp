#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strs[i] == strs[j]) {
                ok = false;
                break;
            }
        }
    }
    char ch[4] = { 'H', 'S', 'D', 'C' };
    char d[5] = { 'A', 'T', 'J', 'Q', 'K' };
    for (int i = 0; i < n; i++) {
        bool ok1 = false;
        for (int j = 0; j < 4; j++) {
            if (strs[i][0] == ch[j]) {
                ok1 = true;
            }
        }
        bool ok2 = false;
        for (int j = 0; j < 5; j++) {
            if (strs[i][1] == d[j]) {
                ok2 = true;
            }
        }
        ok2 |= (strs[i][1] >= '2' && strs[i][1] <= '9');
        if (ok1 && ok2) { } else { ok = false; }
        if (!ok) break;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}