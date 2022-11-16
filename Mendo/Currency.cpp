// Task: https://mendo.mk/Task.do?id=623

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct val {
    long double back;
    long double gain;
    int node;
    vector<int> seq;

    bool operator<(const val& other) const {
        return (gain < other.gain);
    }
};

bool comp(const vector<int>& x, const vector<int>& y) {
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > y[i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<long double>> c(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    const long double scale = (1LL << 20);
    const long double diff = 1.01000000000000000000001;
    const long double target = scale * diff;
    vector<int> ans(n + 10, -1);
    bool found = false;

    for (int i = 0; i < n; i++) {
        // start with some number of c-it currency
        vector<long double> best(n, 0);
        vector<int> parent(n, -1);
        priority_queue<val, vector<val>, less<val>> pq;
        best[i] = scale;
        for (int u = 0; u < n; u++) {
            if (u == i) continue;
            pq.push({ scale * c[i][u] * c[u][i], scale * c[i][u], u, {i, u} });
            best[u] = scale * c[i][u];
            parent[u] = i;
        }
        int it = 0;
        while (!pq.empty()) {
            it++; if (it > 3000) break;
            auto top = pq.top();
            pq.pop();
            if (top.back > target) {
                vector<int> ex = top.seq;
                if (ex.size() < ans.size()) ans = ex;
                else if (ex.size() == ans.size() && comp(ex, ans)) {
                    // This is not said in the task, but you should
                    // give the lexicographically smallest sequence as well
                    ans = ex;
                }
                found = true;
                continue;
            }

            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                if (top.node == k) continue;
                long double gain = top.gain * c[top.node][k];
                long double back = gain * c[k][i];
                if (back > target) {
                    vector<int> ex = top.seq;
                    ex.push_back(k);
                    if (ex.size() < ans.size()) ans = ex;
                    found = true;
                } else if (gain > best[k]) {
                    best[k] = gain;
                    vector<int> tmp_par = top.seq;
                    tmp_par.push_back(k);
                    pq.push({ back, gain, k, tmp_par });
                    parent[k] = top.node;
                }
            }
        }
    }
    if (!found || ans.size() > n) {
        cout << "ne postoi profitabilna sekvenca" << endl;
    } else {
        assert(ans[0] != -1);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1 << "-";
        }
        cout << ans[0] + 1 << endl;
    }
    return 0;
}