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
};

int main() {
    int N, D;
    cin >> N >> D;
    vector<Point<ll>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((points[i]-points[j]).dist2() <= (ll)D * D) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    queue<int> bfs;
    bfs.push(0);
    vector<int> ans(N);
    ans[0] = 1;
    while (!bfs.empty()) {
        auto t = bfs.front();
        bfs.pop();
        for (auto v: adj[t]) {
            if (ans[v]) continue;
            ans[v] = true;
            bfs.push(v);
        }
    }
    for (auto el: ans) {
        cout << (el ? "Yes" : "No") << endl;
    }
    return 0;
}