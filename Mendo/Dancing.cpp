// Task: https://mendo.mk/Task.do?id=300

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n, -1);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    int merge(int a, int b) {
        swap(a, b);
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        // if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

struct p {
    int x, y, diff;

    bool operator>(const p& other) const {
        if (diff == other.diff) return min(x, y) > min(other.x, other.y);
        return diff > other.diff;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<int> g(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    
    priority_queue<p, vector<p>, greater<p>> pq;
    for (int i = 2; i <= n; i++) {
        if (g[i] != g[i-1]) {
            pq.push({ i-1, i, abs(a[i] - a[i-1]) });
        }
    }

    dsu dsu_front(n + 2), dsu_back(n + 2);
    vector<bool> visited(n + 2, false);
    vector<pair<int, int>> ans;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if (visited[top.x] || visited[top.y]) continue;
        visited[top.x] = true;
        visited[top.y] = true;
        ans.push_back({ top.x, top.y });
        
        int left = dsu_back.find_set(top.x - 1);
        int right = dsu_front.find_set(top.y + 1);

        if (left != 0 && right != n + 1) {
            if (g[left] != g[right]) {
                pq.push({ left, right, abs(a[left] - a[right]) });
            }
        }

        dsu_front.merge(top.x, top.y + 1);
        dsu_back.merge(top.y, top.x - 1);
    }

    cout << ans.size() << endl;
    for (auto p: ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}