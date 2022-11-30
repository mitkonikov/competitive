// Task: https://mendo.mk/Task.do?id=153

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    string c;
    cin >> c;
    deque<int> dq;
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        dq.push_back(c[i] - '0');
    }
    int bal = 0;
    int sign = 0;
    stack<pair<int, int>> sign_ch;
    int n = s.size();
    int last_count = 0;
    bool tmp_flip = 0;
    vector<vector<int>> pos(2, vector<int>(s.size(), 0));
    vector<vector<int>> acc(2, vector<int>(s.size(), 0));
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            last_count++;
        } else {
            if (last_count > 0) {
                for (int k = 0; k < last_count; k++) {
                    pos[sign^tmp_flip][k]++;
                }
                last_count = 0;
                tmp_flip = 0;
            }

            if (s[i] == '+') {
                if (s[i+1] == '(') {
                    sign_ch.push({ 0, 0 });
                }
                continue;
            }
            
            if (s[i] == '-') {
                if (s[i+1] == '(') {
                    sign_ch.push({ 1, 0 });
                } else {
                    tmp_flip = 1;
                }
                continue;
            }

            if (s[i] == '(') {
                bal++;
                if (!sign_ch.empty()) {
                    if (sign_ch.top().second == 0) {
                        sign ^= sign_ch.top().first;
                    }
                    auto p = sign_ch.top();
                    sign_ch.pop();
                    p.second = 1;
                    sign_ch.push(p);
                }
                continue;
            }

            if (s[i] == ')') {
                bal--;
                sign ^= sign_ch.top().first;
                if (!sign_ch.empty()) {
                    sign_ch.pop();
                }
                continue;
            }

            assert(false);
        }
    }
    for (int k = 0; k < last_count; k++) {
        pos[sign^tmp_flip][k]++;
    }
    for (int k = s.size() - 1; k >= 0; k--) {
        while (pos[0][k] > 0) {
            acc[0][k] += dq.back();
            assert(!dq.empty());
            dq.pop_back();
            pos[0][k]--;
        }
    }
    for (int k = s.size() - 1; k >= 0; k--) {
        while (pos[1][k] > 0) {
            acc[1][k] += dq.front();
            assert(!dq.empty());
            dq.pop_front();
            pos[1][k]--;
        }
    }
    ll ans = 0;
    ll pow = 1;
    for (int i = 0; i < min((int)s.size(), 9); i++) {
        ans += (ll)acc[0][i] * pow;
        ans -= (ll)acc[1][i] * pow;
        pow *= 10;
    }
    cout << ans << endl;
    return 0;
}