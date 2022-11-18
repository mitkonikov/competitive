// Task: https://mendo.mk/Task.do?id=53

#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct point {
    int x, y;
    
    int man(const point& other) const {
        return abs(x - other.x) + abs(y - other.y);
    }

    int area(const point& other) const {
        return (abs(x - other.x) + 1) * (abs(y - other.y) + 1);
    }

    pair<point, point> corners(const point& other) const {
        return { { x, other.y }, { other.x, y } };
    }

    friend ostream& operator<<(ostream &os, const point &p) {
        os << "(" << p.x << ", " << p.y << ") "; return os;
    }
};

vector<point> points;
int H, V, N;

inline bool umin(int& x, int y) {
    if (y < x) {
        x = y;
        return true;
    } return false;
}

inline pair<string, int> distinct(point p) {
    int mn = INT_MAX;
    int id = -1;
    for (int i = 0; i < N; i++) {
        if (umin(mn, p.man(points[i]))) {
            id = i;
        }
    }
    int count = 0;
    string ind = "";
    for (int i = 0; i < N; i++) {
        if (p.man(points[i]) == mn) {
            ind += ('0' + i);
        }
    }
    sort(ind.begin(), ind.end());
    return { ind, id };
}

int dfs(point p1, point p2) {
    auto [c1, c2] = p1.corners(p2);
    vector<point> ps = { p1, p2, c1, c2 };
    int to_what = -1;
    bool to_what_ok = true;
    bool ok = true;
    bool all_indecisive = true;
    set<string> s;
    for (int i = 0; i < 4; i++) {
        auto ret = distinct(ps[i]);
        if (ret.first.size() != 1) {
            ok = false;
            s.insert(ret.first);
        } else {
            all_indecisive = false;
            if (to_what == -1) to_what = ret.second;
            else if (to_what != ret.second) to_what_ok = false;
        }
    }

    if (all_indecisive && s.size() == 1) {
        return p1.area(p2);
    }

    if (p1.x == p2.x && p1.y == p2.y) {
        return !ok;
    }

    if (ok && to_what_ok) {
        return 0;
    }

    if (p1.x == p2.x) {
        int mid_y = (p1.y + p2.y) / 2;
        int s1 = dfs(p1, { p1.x, mid_y });
        int s2 = dfs({ p1.x, mid_y + 1 }, p2);
        return s1 + s2;
    }

    if (p1.y == p2.y) {
        int mid_x = (p1.x + p2.x) / 2;
        int s1 = dfs(p1, { mid_x, p1.y });
        int s2 = dfs({ mid_x + 1, p1.y }, p2);
        return s1 + s2;
    }

    int mid_y = (p1.y + p2.y) / 2;
    int mid_x = (p1.x + p2.x) / 2;
    int s1 = dfs({ p1.x,    p1.y    }, { mid_x,   mid_y });
    int s2 = dfs({ mid_x+1, p1.y    }, { p2.x,    mid_y });
    int s3 = dfs({ p1.x,    mid_y+1 }, { mid_x,   p2.y });
    int s4 = dfs({ mid_x+1, mid_y+1 }, { p2.x,    p2.y });
    return s1 + s2 + s3 + s4;
}

int main() {
    cin >> H >> V >> N;
    points.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    cout << dfs({ 1, 1 }, { H, V }) << endl;
    return 0;
}