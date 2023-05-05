#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Aho {
    vector<string> dict;
    string text;
    int D;

    vector<vector<int>> g;
    vector<int> suf;
    vector<vector<int>> out;
    vector<int> visited;
    vector<bool> marked;
    vector<bool> ans;
    queue<int> bfs;
    int nodes = 1;
    
    Aho() {
        cin >> text;
        cin >> D;
        dict.resize(D);
        for (int i = 0; i < D; i++) {
            cin >> dict[i];
        }

        g.resize(10, vector<int>(26, -1));
        out.resize(10);
    }

    void build() {
        // add all of the strings
        for (int i = 0; i < D; i++) {
            string& s = dict[i];
            int cur = 0;
            for (int j = 0; j < s.size(); j++) {
                if (g[cur][s[j] - 'a'] == -1) {
                    g[cur][s[j] - 'a'] = nodes++;
                    g.push_back(vector<int>(26, -1));
                    out.push_back({});
                }
			    cur = g[cur][s[j] - 'a'];
            }

            out[cur].push_back(i);
        }

        for (int i = 0; i < 26; i++) if (g[0][i] == -1) g[0][i] = 0;

        suf.resize(nodes, -1);
        queue<int> q;
        for (int ch = 0; ch < 26; ch++) {
            if (g[0][ch] != 0) {
                suf[g[0][ch]] = 0;
                q.push(g[0][ch]);
            }
        }

        while (!q.empty()) {
            int state = q.front();
            q.pop();

            for (int ch = 0; ch < 26; ch++) {
                if (g[state][ch] == -1) continue;
                
                int fail = suf[state];
                while (g[fail][ch] == -1) {
                    fail = suf[fail];
                }

                suf[g[state][ch]] = g[fail][ch];
                q.push(g[state][ch]);
            }
        }
    }

    // BFS over the suffix tree
    void BFS() {
        while (!bfs.empty()) {
            auto state = bfs.front();
            bfs.pop();

            if (suf[state] != -1 && !marked[suf[state]]) {
                marked[suf[state]] = true;
                bfs.push(suf[state]);
            }
        }
    }

    void search() {
        marked.resize(nodes);

        int state = 0;
        for (int i = 0; i < text.size(); i++) {
            char c = text[i];
            while (g[state][c - 'a'] == -1) {
                state = suf[state];
            }
		    state = g[state][c - 'a'];

            if (state == -1) continue;
            if (!marked[state]) bfs.push(state);
            marked[state] = true;
        }

        BFS();
        ans.resize(D);
        for (int state = 0; state < nodes; state++) {
            if (marked[state]) {
                for (auto str: out[state]) {
                    ans[str] = true;
                }
            }
        }

        for (int i = 0; i < D; i++) {
            cout << (ans[i] ? "YES" : "NO") << endl;
        }
    }
};

int main() {
    Aho aho;
    aho.build();
    aho.search();
}