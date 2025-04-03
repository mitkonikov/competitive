#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
struct dsu {
    vector<int> parent;
    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
 
    int find_set(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }
 
    void merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return;
        parent[x] = y;
    }
};
 
struct Line {
    mutable ll k, m, p, id;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};
 
struct LC : multiset<Line, less<>> {
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m, ll id) {
        auto z = insert({ k, m, 0, id }), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    pair<ll, ll> query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return make_pair(-l.k * x - l.m, l.id);
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first.first;
        points[i].second = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> points[i].first.second;
    }
    sort(points.begin(), points.end());
    vector<pair<pair<int, int>, int>> bounds;
    dsu ANS(N);
    for (int i = 0; i < N; i++) {
        while (bounds.size() && points[i].first.first >= bounds.back().first.first &&
                                points[i].first.second >= bounds.back().first.second) {
                ANS.merge(points[bounds.back().second].second, points[i].second);
                bounds.pop_back();
            }
        
        bounds.push_back({ points[i].first, i });
    }
 
    LC container;
    vector<ll> dp(bounds.size());
    vector<int> rec(bounds.size());
    int id = bounds[0].second;
    dp[0] = (ll)points[id].first.first * points[id].first.second;
    container.add(-points[id].first.second, 0, 0);
    rec[0] = -1;
    for (int k = 1; k < bounds.size(); k++) {
        int i = bounds[k].second;
        auto [y1, j] = container.query(points[i].first.first);
        ll y2 = (ll)points[i].first.first * points[i].first.second + dp[k-1];
        if (y1 < y2) {
            dp[k] = y1;
            rec[k] = j;
        } else {
            dp[k] = y2;
            rec[k] = k;
        }
 
        container.add(-points[i].first.second, -dp[k-1], k);
    }
 
    vector<pair<int, int>> ranges;
    for (int i = rec.size() - 1; i >= 0; i = rec[i] - 1) {
        if (rec[i] < 0) break;
        ranges.push_back({ rec[i], i });
    }
 
    for (int i = 0; i < ranges.size(); i++) {
        for (int j = max(0, ranges[i].first); j <= ranges[i].second; j++) {
            int a = bounds[max(0, ranges[i].first)].second;
            int b = bounds[j].second;
            ANS.merge(points[a].second, points[b].second);
        }
    }
 
    map<int, vector<int>> comps;
    for (int i = 0; i < N; i++) {
        comps[ANS.find_set(i)].push_back(i);
    }
 
    cout << comps.size() << endl;
    for (auto& [id, comp] : comps) {
        for (int i = 0; i < comp.size(); i++) {
            cout << comp[i] + 1 << " \n"[i==comp.size()-1];
        }
    }
    return 0;
}