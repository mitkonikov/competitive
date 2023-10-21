#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<map<string, int>> str, missed;
vector<int> paths;

int dfs(int u) {
    paths[u] = adj[u].empty();
    for (auto v: adj[u]) {
        paths[u] += dfs(v);
    }

    int childs = adj[u].size();
    if (childs) {
        for (int i = 1; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (str[adj[u][0]].size() < str[v].size()) {
                swap(adj[u][0], adj[u][i]);
            }
        }

        for (int i = 1; i < adj[u].size(); i++) {
            int v = adj[u][i];
            for (auto& [S, frq]: str[v]) {
                str[adj[u][0]][S]++;
            }
        }
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            for (auto& [S, frq]: missed[v]) {
                if (str[adj[u][0]][S] == childs - 1) {
                    if (str[u][S]) {
                        str[adj[u][0]][S] = childs;
                    } else {
                        missed[u][S]++;
                    }
                }
            }
        }

        vector<string> to_erase;
        for (auto& [S, frq]: str[adj[u][0]]) {
            if (frq == childs - 1) {
                int what_child_lacks = adj[u][0];
                for (int k = 1; k < adj[u].size(); k++) {
                    int v = adj[u][k];
                    if (str[v].find(S) == str[v].end()) {
                        what_child_lacks = v;
                    }
                }
                if (paths[what_child_lacks] == 1) {
                    if (str[u][S]) {
                        str[adj[u][0]][S] = childs;
                        continue;
                    } else {
                        missed[u][S] = 1;
                    }
                }
            }
            if (frq < childs) {
                to_erase.push_back(S);
            }
        }
        for (auto& el: to_erase) {
            str[adj[u][0]].erase(el);
        }

        if (childs == 1 && paths[u] == 1) {
            auto& a = str[u];
            auto& b = str[adj[u][0]];
            if (b.size() > a.size()) {
                a.swap(b);
            }
            for (auto& el: b) {
                a.insert(el);
            }
        } else {
            str[u].swap(str[adj[u][0]]);
        }
    }
    return paths[u];
}

void testCase() {
    int N;
    cin >> N;
    vector<int> P(N);
    adj.clear();
    adj.resize(N);
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
        adj[P[i]].push_back(i);
    }
    str.clear();
    str.resize(N);
    missed.clear();
    missed.resize(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            string S;
            cin >> S;
            str[i][S] = 1;
        }
    }
    paths.clear();
    paths.resize(N);
    dfs(0);
    cout << str[0].size() << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}