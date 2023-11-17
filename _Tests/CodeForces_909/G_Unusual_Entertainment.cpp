#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> timer_in, timer_out;

struct FenwickTree {
    vector<int> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    int getFWT(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }

    int getFWT(int l, int r) {
        return getFWT(r) - (l ? getFWT(l-1) : 0);
    }
};

int timer = 0;
void dfs(int u, int p = -1) {
    timer_in[u] = timer;
    for (auto v: adj[u]) {
        if (v == p) continue;
        timer++;
        dfs(v, u);
    }
    timer_out[u] = timer;
}

const int magic = 320;
struct Query {
    int id;
    int l, r, x;

    bool operator<(const Query &rhs) const {
        if (l / magic == rhs.l / magic) return r < rhs.r;
        return (l / magic < rhs.l / magic);
    }

    void read(int i) {
        id = i;
        cin >> l >> r >> x;
        l--; r--; x--;
    }
};

void testCase() {
    int N, Q;
    cin >> N >> Q;
    adj.clear();
    timer_in.clear();
    timer_out.clear();
    adj.resize(N);
    timer_in.resize(N);
    timer_out.resize(N);
    timer = 0;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    FenwickTree fwt(N + 10);
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        queries[i].read(i);
    }
    sort(queries.begin(), queries.end());
    auto add = [&](int i) {
        fwt.addFWT(timer_in[P[i]]);
    };
    auto remove = [&](int i) {
        fwt.addFWT(timer_in[P[i]], -1);
    };
    vector<int> ans_vec(Q);
    int cur_l = 0, cur_r = -1;
    for (int i = 0; i < Q; i++) {
        while (cur_l > queries[i].l) {
            cur_l--;
            add(cur_l);
        }

        while (cur_r < queries[i].r) {
            cur_r++;
            add(cur_r);
        }

        while (cur_l < queries[i].l) {
            remove(cur_l);
            cur_l++;
        }

        while (cur_r > queries[i].r) {
            remove(cur_r);
            cur_r--;
        }

        int count = fwt.getFWT(timer_in[queries[i].x], timer_out[queries[i].x]);
        ans_vec[queries[i].id] = (count > 0);
    }
    for (auto el: ans_vec) {
        cout << (el ? "YES" : "NO") << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}