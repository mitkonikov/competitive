#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MXP = 3e6 + 1000;
int lp[MXP + 1], pr[MXP + 1];

struct Sieve {
    int counter = 0;

    Sieve() {
        for (int i = 0; i < MXP; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }

        for (int i = 2; i <= MXP; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= MXP;
                 ++j)
                lp[i * pr[j]] = pr[j];
        }
    }

    set<int> decomp(int n) {
        set<int> result;
        while (lp[n] > 1) {
            result.insert(lp[n]);
            n /= lp[n];
        }
        return result;
    }
};

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
    cin.tie(0)->sync_with_stdio(0);
    Sieve s;
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    
    TWOSAT sat(N + 2e6);

    for (int i = 0; i < N; i++) {
        sat.add_disjunction(2 * i, false, 2 * i + 1, false);
        sat.add_disjunction(2 * i, true, 2 * i + 1, true);
    }

    map<int, vector<int>> primes_ids;
    for (int i = 0; i < N; i++) {
        vector<set<int>> p(2);
        p[0] = s.decomp(A[i].first);
        p[1] = s.decomp(A[i].second);

        for (int rep: { 0, 1 }) {
            for (auto prime: p[rep]) {
                primes_ids[prime].push_back(2 * i + rep);
            }
        }
    }

    int aux = 2 * N + 5;
    for (auto [p, ids]: primes_ids) {
        auto current_ids = ids;
        while (current_ids.size() > 1) {
            vector<int> next_ids;
            for (int j = 0; j < static_cast<int>(current_ids.size()) - 1; j += 2) {
                sat.add_disjunction(current_ids[j], true, aux, false);
                sat.add_disjunction(current_ids[j + 1], true, aux, false);
                sat.add_disjunction(current_ids[j], true, current_ids[j+1], true);
                next_ids.push_back(aux);
                aux++;
            }

            if (static_cast<int>(current_ids.size()) % 2 == 1) {
                next_ids.push_back(current_ids.back());
            }

            current_ids.swap(next_ids);
        }
    }

    cout << (sat.solve_2SAT() ? "Yes" : "No") << endl;
    return 0;
}