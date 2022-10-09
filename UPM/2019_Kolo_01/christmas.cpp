#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> depth;
int root;
int n;

vector<vector<int>> tmp;
vector<bool> visited;

vector<vector<int>> friends;
vector<int> X, Y;

vector<vector<int>> same_depth;
vector<int> colors;

void is_root(int node) {
    visited[node] = true;
    for (auto v: tmp[node]) {
        if (v != -1 && !visited[v]) {
            is_root(v);
        }
    }
}

void dfs(int node, int d) {
    depth[node] = d;
    for (auto v: tmp[node]) {
        if (v != -1) dfs(v, d + 1);
    }
}

void plot_dfs(int node) {
    assert(tmp[node].size() <= 2);

    same_depth[depth[node]].push_back(node);
    
    int LEFT = tmp[node][0];
    int RIGHT = tmp[node][1];

    if (LEFT == -1 && RIGHT == -1) return;

    if (LEFT != -1) {
        friends[node].push_back(LEFT);
        friends[LEFT].push_back(node);
        plot_dfs(LEFT);
    }

    if (RIGHT != -1) {
        friends[node].push_back(RIGHT);
        friends[RIGHT].push_back(node);
        plot_dfs(RIGHT);        
    }
}

void precomp() {
    X.resize(n);
    Y.resize(n);
    same_depth.resize(n);
    plot_dfs(root);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < same_depth[depth[i]].size(); k++) {
            if (same_depth[depth[i]][k] == i) {
                if (k-1 >= 0) {
                    int L = same_depth[depth[i]][k-1];
                    friends[i].push_back(L);
                }
                
                if (k+1 < same_depth[depth[i]].size()) {
                    int R = same_depth[depth[i]][k+1];
                    friends[i].push_back(R);
                }
            }
        }
    }

    // we got the friends
    colors.resize(n, 0);

    queue<int> bfs;
    bfs.push(root);
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();

        if (colors[top] != 0) continue;
    
        for (int t = 1; t <= 10; t++) {
            bool ok = true;
            for (auto ff: friends[top]) {
                if (ff != top && colors[ff] == t) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                colors[top] = t;
                break;
            }
        }

        for (auto f: friends[top]) {
            if (colors[f] == 0) bfs.push(f);
        }
    }
}

int main() {
    cin >> n;

    tmp.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tmp[i].push_back(a-1);
        tmp[i].push_back(b-1);
    }

    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        fill(visited.begin(), visited.end(), false);
        is_root(i);
        bool ok = true;
        for (int k = 0; k < n; k++) if (!visited[k]) {
            ok = false;
            break;
        }

        if (ok) {
            root = i;
            break;
        }
    }

    depth.resize(n, 0);
    dfs(root, 0);

    friends.resize(n);
    precomp();

    for (int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    cout << flush;
    return 0;
}