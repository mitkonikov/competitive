#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    for (ll i = 0; i * i <= 1e14; i++) {
        string num = to_string(i * i);
        if (num.size() <= S.size()) {
            vector<int> frq(10, 0);
            for (int u = 0; u < num.size(); u++) {
                frq[num[u] - '0']--;
            }
            for (int u = 0; u < S.size(); u++) {
                frq[S[u] - '0']++;
            }
            bool ok = 1;
            for (int u = 1; u < 10; u++) ok &= (frq[u] == 0);
            if (ok && frq[0] >= 0) ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}