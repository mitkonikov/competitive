#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    const int N = S.size();
    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 3; j <= N - i; j++) {
            string s = S.substr(i, j);
            if (s[0] != 't' || s.back() != 't') continue;
            int t = 0;
            for (char el : s) {
                if (el == 't') t++;
            }
            ans = max(
                ans,
                (double)(t - 2) / (s.size() - 2)
            );
        }
    }
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}