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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<string> v;
    v.push_back(string(1, S[0]));
    for (int i = 1; i < N; i++) {
        if (S[i] == v.back()[0]) {
            v.back() += S[i];
        } else {
            v.push_back(string(1, S[i]));
        }
    }
    int c = 0;
    rep(i, 0, sz(v)) {
        if (v[i][0] == '1') {
            c++;
            if (c == K) {
                swap(v[i], v[i-1]);
                break;
            }
        }
    }
    rep(i, 0, sz(v)) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}