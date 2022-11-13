#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = INT_MAX / 10; 

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int n;
vector<vector<pair<int, int>>> adj;
vector<bool> whole;
int whole_mask = 0;
vector<string> s;
vector<vector<int>> matches;
vector<unordered_map<int, int>> dp(10);

int dfs(int u, int mask) {
    auto it = dp[u].find(mask);
    if (it != dp[u].end()) return it->second;
    if ((mask | whole_mask) == (1 << n) - 1) return 0;
    int result = INF;
    for (int v = 0; v < n; v++) {
        if (whole[v]) continue;
        if ((1 << v) & mask) continue;
        int len = matches[u][v];
        int d = dfs(v, mask | (1 << v)) + max(0, (int)(s[v].size() - len));
        result = min(result, d);
    }
    return dp[u][mask] = result;
}

int main() {
    cin >> n;
    adj.resize(n);
    s.resize(n);
    matches.resize(n, vector<int>(n, 0));
    whole.resize(n, false);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (whole[j]) continue;
            if (i == j) continue;
            string ns = s[i] + s[j];
            auto z = z_function(ns);
            for (int k = s[i].size(); k < z.size(); k++) {
                if (z[k] >= s[i].size()) {
                    whole[i] = true;
                    whole_mask |= (1 << i);
                    break;
                }
                if (z[k] == ns.size() - k && !whole[j] && !whole[i]) {
                    matches[j][i] = max(matches[j][i], min((int)s[i].size(), z[k]));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (whole[i]) continue;
        for (int j = 0; j < n; j++) {
            if (matches[i][j] > 0) {
                adj[i].push_back({ j, matches[i][j] });
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (whole[i]) continue;
        ans = min(ans, dfs(i, (1 << i)) + (int)s[i].size());
    }
    cout << ans << endl;
    return 0;
}