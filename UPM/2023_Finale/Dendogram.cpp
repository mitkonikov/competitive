#include <bits/stdc++.h>
 
using namespace std;
 
vector<string> ans;
struct rec {
    int x, y;
};
 
int x_counter = 0;
 
rec solve(string S, int depth = 0) {
    int bal = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            bal++;
        } else if (S[i] == ')') {
            bal--;
        }
        if (S[i] == ',') {
            if (bal == 0) {
                auto l = S.substr(0, i);
                auto r = S.substr(i + 1);
                rec L = { 0, 0 }, R = { 0, 0 };
                if (l.size() == 1) {
                    L.x = x_counter;
                    ans[L.x][L.y] = l[0];
                    x_counter += 2;
                } else {
                    L = solve(l.substr(1, l.size() - 2), depth + 1);
                }
 
                if (r.size() == 1) {
                    R.x = x_counter;
                    ans[R.x][R.y] = r[0];
                    x_counter += 2;
                } else {
                    R = solve(r.substr(1, r.size() - 2), depth + 1);
                }
 
                int mx = max(R.y, L.y) + 2;
                while (L.y < mx) {
                    L.y++;
                    ans[L.x][L.y] = '-';
                }
                while (R.y < mx) {
                    R.y++;
                    ans[R.x][R.y] = '-';
                }
 
                for (int k = L.x; k <= R.x; k++) {
                    ans[k][mx] = '|';
                }
                
                return {
                    (L.x + R.x) / 2,
                    mx
                };
            }
        }
    }
    return { -1, -1 };
}
 
int main() {
    string S;
    cin >> S;
    if (S.size() == 1) {
        cout << S << endl;
        return 0;
    }
    int count = 0;
    int N = S.size();
    for (int i = 0; i < N; i++) if (S[i] >= 'A' && S[i] <= 'Z') count++;
    ans.resize(2 * N, string(2010, ' '));
 
    solve(S.substr(1, N - 2));
 
    for (auto &el : ans) {
        while (!el.empty() && el.back() == ' ') el.pop_back();
        cout << el << endl;
    }
    return 0;
}