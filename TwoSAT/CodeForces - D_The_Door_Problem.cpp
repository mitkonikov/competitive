#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct TWOSAT {
    int n;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TWOSAT(int n) {
        n = 2 * n + 100;
        this->n = n;
        adj.resize(n);
        adj_t.resize(n);
        used.resize(n);
        order.resize(n);
        comp.resize(n);
        assignment.resize(n);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    // (a or b) and ...
    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> initial(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // INITIAL POSITIONS OF DOORS
        // 0 - LOCKED, 1 - UNLOCKED
        initial[i] = (x == 1);
    }

    TWOSAT sat(m);

    vector<vector<int>> doors(n);
    // EACH DOOR IS CONTROLLED BY EXACTLY TWO SWITCHES
    // THERE ARE M SWITCHES
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int door;
            cin >> door;
            doors[door - 1].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (initial[i] == 0) {
            // if locked
            //   toggle A OR B
            //   toggle NOT(A AND B) -> NOT A OR NOT B
            sat.add_disjunction(doors[i][0], false, doors[i][1], false);
            sat.add_disjunction(doors[i][0], true, doors[i][1], true);
        } else {
            // if already unlocked
            //       toggle A AND B      ->  A OR NULL AND B OR NULL
            //    or toggle NOT (A XOR B)

            //  A B          (NOT A OR B) AND (A OR NOT B)
            //  0 0   1             1               1
            //  0 1   0             1               0
            //  1 0   0             0               1
            //  1 1   1             1               1
            sat.add_disjunction(doors[i][0], true, doors[i][1], false);
            sat.add_disjunction(doors[i][0], false, doors[i][1], true);
        }
    }

    cout << (sat.solve_2SAT() ? "YES" : "NO") << endl;
    return 0;
}