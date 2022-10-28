#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

unordered_map<string, set<string>> mp, rmp;
vector<string> dict;
set<string> conn;
map<string, int> ans;

int main() {
    int n;
    cin >> n;
    dict.reserve(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.push_back(s);
        string start = s.substr(0, 3);
        string end = s.substr(s.size() - 3);

        conn.insert(start);
        conn.insert(end);
        mp[start].insert(end);
        rmp[end].insert(start);
    }

    queue<int> bfs;
    vector<string> v_conn(conn.begin(), conn.end());
    unordered_map<string, int> conn_map;
    vector<int> dp(conn.size(), -1);
    vector<int> count(conn.size(), 0);
    for (int i = 0; i < v_conn.size(); i++) {
        conn_map[v_conn[i]] = i;
        if (mp[v_conn[i]].empty()) {
            dp[i] = 0;
            bfs.push(i);
        }

        count[i] = mp[v_conn[i]].size();
    }

    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        for (auto V: rmp[v_conn[top]]) {
            auto v = conn_map[V];
            if (dp[v] != -1) continue;
            count[v]--;
            if (dp[top] == 1) {
                if (count[v] == 0) {
                    dp[v] = 0;
                    bfs.push(v);
                }
            } else {
                dp[v] = 1;
                bfs.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        auto end = dict[i].substr(dict[i].size() - 3);
        auto ans = dp[conn_map[end]];
        
        if (ans == -1) cout << "Draw" << endl;
        else if (ans == 1) cout << "Aoki" << endl;
        else if (ans == 0) cout << "Takahashi" << endl;
        else assert(false);
    }
    return 0;
}