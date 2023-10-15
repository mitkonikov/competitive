#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    int ans = 1;
    for (int s = 0; s < S.size(); s++) {
        for (int len = 1; s + len <= S.size(); len++) {
            bool is_pal = 1;
            for (int k = 0; k < len; k++) {
                is_pal &= (S[s + k] == S[s + len - 1 - k]);
            }
            if (is_pal) ans = max(ans, len);
        }
    }
    cout << ans << endl;
    return 0;
}