#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
	int N;
	vector<vector<int>> adj;
    vector<int> scc, ids, low;
    int scc_id = 0;
    int node_id = 0;

	stack<int> s;
	vector<bool> in_stack;

    vector<vector<int>> comps;

	void dfs(int u) {
		low[u] = ids[u] = node_id++;
		s.push(u);
		in_stack[u] = true;
		for (int v: adj[u]) {
			if (ids[v] == -1) dfs(v), low[u] = min(low[u], low[v]);
            else if (in_stack[v]) low[u] = min(low[u], ids[v]);
		}
		
		if (low[u] == ids[u]) {
            comps.push_back({ });
			while (true) {
				int v = s.top();
				s.pop();
                comps.back().push_back(v);
				scc[v] = scc_id;
				in_stack[v] = false;
				if (u == v) break;
			}

			scc_id++;
		}
	}

	Tarjan(int n) {
        N = n;
        adj.resize(n);
        scc.resize(n, -1);
        ids.resize(n, -1);
        low.resize(n);
        in_stack.resize(n);
	}

    void solve() {
		for (int i = 0; i < N; i++) if (scc[i] == -1) dfs(i);
        reverse(comps.begin(), comps.end());
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Tarjan tarjan(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tarjan.adj[a].push_back(b);
    }

    tarjan.solve();
    cout << tarjan.comps.size() << endl;
    for (auto &comp: tarjan.comps) {
        cout << comp.size() << " ";
        for (int i = 0; i < comp.size(); i++) cout << comp[i] << " ";
        cout << endl;
    }

	return 0;
}