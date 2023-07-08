#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Point {
    int x, y, z;
};

int domination(vector<Point> v) {
    int n = v.size();
    int ans = 0;
    sort(v.begin(), v.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return (a.x > b.x);
        if (a.y != b.y) return (a.y < b.y); // this is very important
        return (a.z < b.z);
    });

    auto cond = [&](pair<int, int> a, pair<int, int> b) {
        return (a.first > b.first && a.second > b.second);
    };

    // Maintains a data structure, where x is mapped to 
    // the max(y) seen with this x while holding that
    // if x2 > x1 then y2 < y1 for each (x[i], y[i])
    map<int, int> frontier; // { x -> max(y) }
    auto update = [&](Point p) {
        auto it = frontier.find(p.y);
        if (it != frontier.end()) {
            it->second = max(it->second, p.z);
        } else {
            frontier[p.y] = p.z;
            it = frontier.find(p.y);
        }
        
        while (it != frontier.begin() 
            && prev(it)->second <= it->second) {
            frontier.erase(prev(it));
        }

        if (next(it) != frontier.end() && cond(*next(it), { p.y, p.z })) {
            if (it->second <= p.z) frontier.erase(it);
            return true;
        } else {
            return false;
        }
    };

    for (int i = 0; i < n; i++) {
        if (update(v[i])) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Point> A;
    A.reserve(n * 6);
    for (int i = 0; i < n; ++i) {
        vector<int> ps(3);
        scanf("%d %d %d", &ps[0], &ps[1], &ps[2]);
        
        vector<int> order(3);
        iota(order.begin(), order.end(), 0);
        do {
            A.push_back({ ps[order[0]], ps[order[1]], ps[order[2]] });
        } while (next_permutation(order.begin(), order.end()));
    }
    int ans = domination(A);
    cout << (ans ? "Yes" : "No") << endl;
}
