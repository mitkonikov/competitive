#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> openers;
    vector<int> pt, r;
    for (int i = 0; i < N; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            pt.push_back(x);
        } else if (t == 1) {
            r.push_back(x);
        } else {
            openers.push_back(x);
        }
    }
    sort(openers.rbegin(), openers.rend());
    sort(r.rbegin(), r.rend());
    sort(pt.rbegin(), pt.rend());
    r.resize(min((ll)r.size(), accumulate(openers.begin(), openers.end(), 0LL)));
    ll ans = 0;
    // buy all pt cans
    ll h1 = 0;
    for (int i = 0; i < min(M, (int)pt.size()); i++) {
        h1 += pt[i];
    }
    ans = max(ans, h1);
    int left_over = M - min(M, (int)pt.size());
    int op_left = 0;
    int op_pointer = 0;
    int R_pointer = -1;
    if (left_over) {
        for (int i = 0; left_over && i < r.size(); i++) {
            if (op_left == 0) {
                op_left += openers[op_pointer++];
                left_over--;
            }
            if (left_over) {
                h1 += r[i];
                op_left--;
                left_over--;
                R_pointer = i;
            }
        }
        ans = max(ans, h1);
    }
    if (left_over == 0) {
        int P_pointer = min(M, (int)pt.size()) - 1;
        while (P_pointer >= 0) {
            h1 -= pt[P_pointer];
            left_over++;
            // try to update the R pointer
            while (left_over && R_pointer + 1 < r.size()) {
                if (op_left == 0) {
                    op_left += openers[op_pointer++];
                    left_over--;
                }
                if (left_over) {
                    h1 += r[R_pointer + 1];
                    R_pointer++;
                    left_over--;
                    op_left--;
                }
            }
            
            P_pointer--;
            ans = max(ans, h1);
        }
    }
    cout << ans << endl;
    return 0;
}