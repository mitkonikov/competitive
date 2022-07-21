#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define MAXN 100013
int N; // size of dictionary
string dict[MAXN];
string text;

#define MAXM 1100013
int M; // number of states in the automation
int g[MAXM][26]; // the normal edges in the trie
int f[MAXM]; // failure function
LL out[MAXM]; // output function

int aho_corasick() {
	memset(g, -1, sizeof g);
	memset(out, 0, sizeof out);

	int nodes = 1;

	// build the trie
	for (int i = 0; i < N; i++) {
		string& s = dict[i];
		int cur = 0;

		for (int j = 0; j < s.size(); j++) {
			if (g[cur][s[j] - 'a'] == -1) {
				g[cur][s[j] - 'a'] = nodes++;
			}
			cur = g[cur][s[j] - 'a'];
		}
		out[cur] = s.size();
	}

	for (int ch = 0; ch < 26; ch++) {
		if (g[0][ch] == -1) {
			g[0][ch] = 0;
		}
	}

	// BFS to calculate out and failure functions
	memset(f, -1, sizeof f);
	queue<int> q;
	for (int ch = 0; ch < 26; ch++) {
		if (g[0][ch] != 0) {
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}

	while (!q.empty()) {
		int state = q.front();
		q.pop();

		for (int ch = 0; ch < 26; ch++) {
			if (g[state][ch] == -1) continue;

			int fail = f[state];
			while (g[fail][ch] == -1) {
				fail = f[fail];
			}

			f[g[state][ch]] = g[fail][ch];
			out[g[state][ch]] = max(out[g[state][ch]], out[g[fail][ch]]);

			q.push(g[state][ch]);
		}
	}

	return nodes;
}

void search() {
	int state = 0;
	vector<pair<int, int>> events;
    events.reserve(text.size());
    
    vector<char> ans;
    ans.reserve(text.size());

    int id = 0;
    for (char c : text) {
		while (g[state][c - 'a'] == -1) {
			state = f[state];
		}
		state = g[state][c - 'a'];
        if (out[state] != 0) events.push_back({ id - out[state] + 1, id });
        id++;
        // ret += out[state];
	}

    sort(events.begin(), events.end());
    if (events.size() != 0) {
        int current_event = 0;
        for (int i = 0; i < text.size(); i++) {
            while (current_event + 1 < events.size() && i > events[current_event].second) current_event++;
            if (i >= events[current_event].first && i <= events[current_event].second) continue;
            ans.push_back(text[i]);
        }
    }

    for (char c: ans) {
        cout << c;
    } cout << endl;
}

int main() {
	cin >> text;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dict[i];
	}

	M = aho_corasick();
    search();
	return 0;
}