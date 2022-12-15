#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct point {
    ll x, y;
    
    ll man(const point& other) const {
        return abs(x - other.x) + abs(y - other.y);
    }

    pair<point, point> corners(const point& other) const {
        return { { x, other.y }, { other.x, y } };
    }

    friend ostream& operator<<(ostream &os, const point &p) {
        os << "(" << p.x << ", " << p.y << ") "; return os;
    }
};

vector<pair<point, ll>> dists;

void dfs(point p1, point p2) {
    auto [c1, c2] = p1.corners(p2);
    vector<point> ps = { p1, p2, c1, c2 };

    for (int i = 0; i < dists.size(); i++) {
        bool ok = true;
        for (auto p: ps) {
            ok &= (p.man(dists[i].first) < dists[i].second);
        }
        if (ok) return;
    }

    if (p1.x == p2.x && p1.y == p2.y) {
        cout << (ll)p1.x * 4000000 + p1.y << endl;
        exit(0);
    }

    if (p1.x == p2.x) {
        int mid_y = (p1.y + p2.y) / 2;
        dfs(p1, { p1.x, mid_y });
        dfs({ p1.x, mid_y + 1 }, p2);
        return;
    }

    if (p1.y == p2.y) {
        int mid_x = (p1.x + p2.x) / 2;
        dfs(p1, { mid_x, p1.y });
        dfs({ mid_x + 1, p1.y }, p2);
        return;
    }

    int mid_y = (p1.y + p2.y) / 2;
    int mid_x = (p1.x + p2.x) / 2;
    dfs({ p1.x,    p1.y    }, { mid_x,   mid_y });
    dfs({ mid_x+1, p1.y    }, { p2.x,    mid_y });
    dfs({ p1.x,    mid_y+1 }, { mid_x,   p2.y });
    dfs({ mid_x+1, mid_y+1 }, { p2.x,    p2.y });
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll X, Y, A, B;
        cin >> X >> Y >> A >> B;
        ll man = abs(A - X) + abs(B - Y) + 1;
        dists.push_back({ { X, Y }, man });
    } 
    dfs({ 0, 0 }, { 4000000, 4000000 });
    return 0;
}