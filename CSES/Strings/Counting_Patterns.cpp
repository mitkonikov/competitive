#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Aho {
    vector<string> dict;
    string text;
    int D;

    vector<vector<int>> g;
    vector<int> suf;
    vector<vector<int>> rev_suf;
    vector<vector<int>> out;
    vector<int> visited;
    vector<ll> marked;
    vector<ll> ans;
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
        rev_suf.resize(nodes);
        queue<int> q;
        for (int ch = 0; ch < 26; ch++) {
            if (g[0][ch] != 0) {
                suf[g[0][ch]] = 0;
                rev_suf[0].push_back(g[0][ch]);
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
                rev_suf[g[fail][ch]].push_back(g[state][ch]);
                q.push(g[state][ch]);
            }
        }
    }

    // DFS over the suffix tree
    ll DFS(int state) {
        visited[state] = true;
        ll m = marked[state];
        for (auto v: rev_suf[state]) {
            if (visited[v]) continue;
            m += DFS(v);
        }
        for (auto str: out[state]) {
            ans[str] += m;
        }
        return m;
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
            marked[state]++;
        }

        ans.resize(D);
        visited.resize(nodes);
        DFS(0);

        for (int i = 0; i < D; i++) {
            cout << ans[i] << endl;
        }
    }
};

int main() {
    Aho aho;
    aho.build();
    aho.search();
}