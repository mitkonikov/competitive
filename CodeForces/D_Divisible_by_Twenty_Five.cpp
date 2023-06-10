#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; ; i += 25) {
        string t = to_string(i);
        if (t.size() < S.size()) continue;
        if (t.size() > S.size()) break;
        bool f = 0;
        char x = 0;
        for (int j = 0; j < S.size(); j++) {
            if (S[j] == 'X') {
                if (x == 0) {
                    x = t[j];
                } else {
                    if (x != t[j]) {
                        f = 1;
                        break;
                    }
                }
            } else if (S[j] != '_') {
                if (S[j] != t[j]) {
                    f = 1;
                    break;
                }
            }
        }
        ans += !f;
    }
    cout << ans << endl;
    return 0;
}