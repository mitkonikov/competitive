#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

set<string> dict;
int n, m;
vector<string> a;
vector<string> v;
int sum = 0;

inline string conv(vector<string>& str) {
    string res = "";
    for (auto el: str) res += el;
    return res;
}

bool dfs(int i, int ip, vector<string>& res, vector<int>& p) {
    if (i + (n-ip) > 16) return false;
    if (i > 16) return false;
    string r = conv(res);
    if (i <= 16 && ip == n) {
        return !dict.count(r);
    }
    auto& cur = a[p[ip]];
    res.push_back(cur);

    bool c = false;
    if (ip < n-1) {
        res.push_back("");
        c = true;
    }

    string ss = "";
    for (int sp = 1; sp <= 17 - r.size(); sp++) {
        if (ip == n-1) {
            if (dfs(i + cur.size(), ip+1, res, p)) {
                return true;
            } else {
                break;
            }
        }
        ss += "_";
        res.back() = ss;
        if (dfs(i + cur.size() + ss.size(), ip+1, res, p)) {
            return true;
        }
    }

    res.pop_back();
    if (c) res.pop_back();
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    map<string, int> mp;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
        sum += a[i].size();
    }

    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        dict.insert(v[i]);
    }

    random_shuffle(v.begin(), v.end());

    if (n == 1 && m == 0) {
        if (a[0].size() < 3) {
            cout << -1 << endl;
            return 0;
        }
    }

    bool possible = false;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        vector<string> res;
        if (dfs(0, 0, res, p)) {
            cout << conv(res) << endl;
            possible = true;
            break;
        }
    } while (next_permutation(p.begin(), p.end()));

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    cout << flush;
    return 0;
}