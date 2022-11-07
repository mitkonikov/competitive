#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
int main() {
    // freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sz = 100;
    vector<vector<int>> sqL(n / sz + 2, vector<int>(n, INT_MAX));
    vector<vector<int>> sqR(n / sz + 2, vector<int>(n, INT_MAX));
    auto process = [&](vector<vector<int>>& sq) {
        int blocks = 0;
        for (int l = 0; l < n; l++) {
            int L = l * sz;
            if (L >= n) break;
            blocks++;
            int pre = INT_MAX;
            set<int> s;
            for (int i = L; i < n; i++) {
                auto it_lower = s.lower_bound(a[i]);
 
                int lower = INT_MAX;
                int upper = INT_MAX;
                if (it_lower != s.end()) {
                    upper = *it_lower;
                }
                if (it_lower != s.begin()) {
                    it_lower = prev(it_lower);
                    lower = *it_lower;                
                }
 
                if (lower != INT_MAX) sq[l][i] = min({ pre, abs(lower - a[i]) });
                if (upper != INT_MAX) sq[l][i] = min({ sq[l][i], pre, abs(upper - a[i]) });
 
                pre = sq[l][i];
                s.insert(a[i]);
            }
        }
        return blocks;
    };
 
    int blocks = process(sqL);
    reverse(a.begin(), a.end());
    assert(blocks == process(sqR));
    reverse(a.begin(), a.end());
     
    int last_answer = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l = ((ll)l + last_answer + n) % n;
        r = ((ll)r + last_answer + n) % n;
 
        last_answer = INT_MAX;
 
        int l_block = (l / sz + (l % sz != 0));
        int r_block = ((n - 1 - r) / sz + ((n - 1 - r) % sz != 0));
 
        if (l_block < blocks) {
            last_answer = min(last_answer, sqL[l_block][r]);
        }
 
        if (r_block < blocks) {
            last_answer = min(last_answer, sqR[r_block][n-1-l]);
        }
 
        vector<int> sides;
        int l_most = 0;
        for (int L = l; L <= min(r, l_block * sz); L++) {
            sides.push_back(a[L]);
            l_most = L;
        }
 
        for (int R = r; R >= max({ n - 1 - (r_block * sz), l, l_most + 1 }); R--) {
            sides.push_back(a[R]);
        }
 
        sort(sides.begin(), sides.end());
        for (int i = 1; i < sides.size(); i++) {
            last_answer = min(last_answer, abs(sides[i] - sides[i-1]));
        }
 
        cout << last_answer << endl;
    }
    return 0;
}