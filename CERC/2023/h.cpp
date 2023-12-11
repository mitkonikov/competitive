#include <bits/stdc++.h>
 
using namespace std;
 
int id = 0;
map<string, int> mp;
map<int, string> rmp;
 
int add(string name) {
    auto it = mp.find(name);
    if (it == mp.end()) {
        mp[name] = id;
        rmp[id] = name;
        id++;
        return mp[name];
    }
    return it->second;
}
 
vector<string> split(string S) {
    vector<string> result;
    string newS = "";
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == ' ') {
            if (newS.empty()) continue;
            result.push_back(newS);
            newS = "";
        } else {
            newS += S[i];
        }
    }
    if (!newS.empty()) {
        result.push_back(newS);
    }
    return result;
}
 
string ans = "";
 
void dfs(int u, vector<vector<int>>& adj) {
    ans += "1";
    cout << rmp[u] << endl;
    for (auto v: adj[u]) {
        dfs(v, adj);
    }
    ans += "0";
}
 
void encode() {
    ans = "";
    vector<vector<int>> adj(1000);
    string S;
    while (!getline(cin, S).eof()) {
        auto v = split(S);
        v[0].pop_back();
        for (int i = 1; i < v.size(); i++) {
            adj[add(v[0])].push_back(add(v[i]));
        }
    }
    dfs(0, adj);
    cout << ans << endl;
}
 
int ans_id = 0;
int name_id = 0;
vector<string> names;
vector<vector<string>> output;
 
int id_new = 0;
 
string dfs2(int id) {
    output[id].push_back(names[name_id]);
    ans_id++;
    name_id++;
    while (ans_id < ans.size() && ans[ans_id] == '1') {
        id_new++;
        output[id].push_back(dfs2(id_new));
    }
    ans_id++;
    return output[id][0];
}
 
void decode() {
    string S;
    while (!getline(cin, S).eof()) {
        if (S[0] == '0' || S[0] == '1') {
            ans = S;
            break;
        } else {
            names.push_back(S);
        }
    }
    output.resize(names.size());
    dfs2(0);
    int N = output.size();
    for (int i = 0; i < N; i++) {
        if (output[i].size() == 1) continue;
        cout << output[i][0] << ": ";
        for (int j = 1; j < output[i].size(); j++) cout << output[i][j] << " ";
        cout << endl;
    }
}
 
int main() {
    string COMMAND;
    getline(cin, COMMAND);
    if (COMMAND == "ENCODE") {
        encode();
    } else {
        decode();
    }
    return 0;
}
