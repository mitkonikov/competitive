#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0, cl = 0;
    rep(i, 0, sz(s)) {
        if (s[i] == 'O') {
            cl++;
            if (cl == k) {
                cl = 0;
                ans++;
            }
        } else {
            cl = 0;
        }
    }
    cout << ans << endl;
    return 0;
}