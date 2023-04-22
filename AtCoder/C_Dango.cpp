#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = -1;
    auto solve = [&](string s) {
        int current = 0;
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'o') {
                current++;
            } else {
                if (current == 0) continue;
                ans = max(ans, current);
                current = 0;
            }
        }
        return ans;
    };
    ans = max(ans, solve(S));
    reverse(S.begin(), S.end());
    ans = max(ans, solve(S));
    cout << ans << endl;
    return 0;
}