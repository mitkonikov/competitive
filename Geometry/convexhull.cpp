#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct point {
    ll x, y;
};

bool isNotRightTurn(const point &a, const point &b, const point &c) {
    long long cross = (long long)(a.x - b.x) * (c.y - b.y) - (long long)(a.y - b.y) * (c.x - b.x);
    long long dot = (long long)(a.x - b.x) * (c.x - b.x) + (long long)(a.y - b.y) * (c.y - b.y);
    return cross < 0 || (cross == 0 && dot <= 0);
}

// returns the convex hull in counterclockwise order
vector<point> convex_hull(vector<point> points) {
    sort(points.begin(), points.end(), [](auto a, auto b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    int n = points.size();
    vector<point> hull;
    for (int i = 0; i < 2 * n - 1; i++) {
        int j = i < n ? i : 2 * n - 2 - i;
        while (hull.size() >= 2 && isNotRightTurn(hull.end()[-2], hull.end()[-1], points[j]))
            hull.pop_back();
        hull.push_back(points[j]);
    }
    hull.pop_back();
    return hull;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        set<pair<int, int>> points;
        vector<point> vec;
        vec.reserve(n);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            if (points.count(p)) {
                continue;
            }
            points.insert(p);
            vec.push_back({ p.first, p.second });
        }
        if (vec.size() <= 3) {
            cout << vec.size() << endl;
            for (auto el: vec) {
                cout << el.x << " " << el.y << endl;
            }
            continue;
        }
        auto res = convex_hull(vec);
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].x << " " << res[i].y << endl;
        }
    }
    cout << flush;
    return 0;
}