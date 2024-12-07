#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repv(i, a) for(int i = 0; i < (a).size(); ++i)
#define repvr(i, a) for(int i = (int)((a).size())-1; i >= 0; --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    string S;
    cin >> S;
    int Q;
    cin>>Q;
    rep(i, 0, Q) {
        ll k;
        cin >> k;
        k--;
        // 000,001,010,011,100
        if (__popcount(k / sz(S)) % 2 == 0) {
            cout << S[k % sz(S)] << " ";
        } else {
            char c = S[k % sz(S)];
            if (c >= 'a' && c <= 'z') {
                cout << (char)(c - 'a' + 'A') << " ";
            } else {
                cout << (char)(c - 'A' + 'a') << " ";
            }
        }
    }
    cout << endl;
    return 0;
}