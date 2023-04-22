#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
unordered_map<string, int> mp;
unordered_map<int, string> rmp;
 
vector<string> split(string& a) {
    vector<string> result;
    string current = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ',') {
            result.push_back(current);
            current = "";
        } else {
            current += a[i];
        }
    }
    if (!current.empty()) result.push_back(current);
    return result;
}
 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;
 
void dfs(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
 
    order.push_back(u);
}
 
int main() {
    int R;
    cin >> R;
    int id = 0;
    auto add = [&](string s) {
        auto it = mp.find(s);
        if (it != mp.end()) {
            return it->second;
        }
        mp[s] = id;
        rmp[id] = s;
        id++;
        return id - 1;
    };
    
    vector<vector<int>> rows(R);
 
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        auto v = split(s);
        for (auto ss: v) {
            rows[i].push_back(add(ss));
        }
    }
 
    adj.resize(id + 10);
    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows[i].size() - 1; j++) {
            int u = rows[i][j];
            int v = rows[i][j + 1];
            adj[u].push_back(v);
        }
    }
 
    visited.resize(id + 10);
    for (int i = 0; i < id; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
 
    reverse(order.begin(), order.end());
 
    vector<int> where(id + 10);
    for (int i = 0; i < order.size(); i++) {
        where[order[i]] = i;
    }
 
    bool ok = true;
    for (int i = 0; i < R && ok; i++) {
        for (int j = 0; j < rows[i].size() - 1; j++) {
            int u = rows[i][j];
            int v = rows[i][j + 1];
            if (where[u] > where[v]) {
                ok = false;
                break;
            }
        }
    }
 
    if (!ok) {
        cout << "NAPAKA V PODATKIH" << endl;
        return 0;
    }
    
    for (int i = 0; i < order.size(); i++) {
        cout << rmp[order[i]];
        if (i < order.size() - 1) cout << ",";
    } cout << endl;
 
    return 0;
}