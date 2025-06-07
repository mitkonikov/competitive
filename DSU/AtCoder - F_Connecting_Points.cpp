#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
    void GCD() {
        int GCD = gcd(x, y);
        x /= GCD; y /= GCD;
    }
    T man(P p) {
        return abs(x - p.x) + abs(y - p.y);
    }
};

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
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
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

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<Point<int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    struct CON {
        int u, v, dist;
        bool operator>(const CON& other) const {
            return dist > other.dist;
        }
    };
    priority_queue<CON, vector<CON>, greater<CON>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto dist = points[j].man(points[i]);
            pq.push(CON{ j, i, dist });
        }
    }
    dsu DSU(N + Q);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int X, Y;
            cin >> X >> Y;
            points.push_back(Point<int>{ X, Y });
            for (int j = 0; j < points.size() - 1; j++) {
                auto dist = points[j].man(points.back());
                pq.push(CON{ j, (int)points.size() - 1, dist });
            }
        } else if (t == 2) {
            while (!pq.empty() && DSU.are_same(pq.top().u, pq.top().v)) {
                pq.pop();
            }

            if (pq.empty()) {
                cout << -1 << endl;
                continue;
            }

            auto top = pq.top();
            pq.pop();
            DSU.merge(top.u, top.v);
            while (!pq.empty() && pq.top().dist == top.dist) {
                auto new_top = pq.top();
                pq.pop();
                DSU.merge(new_top.u, new_top.v);
            }
            
            cout << top.dist << endl;
        } else if (t == 3) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            cout << (DSU.are_same(u, v) ? "Yes" : "No") << endl;
        } else {
            assert(false);
        }
    }
    return 0;
}