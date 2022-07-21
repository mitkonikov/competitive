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
    int n, k;
    cin >> n >> k;
    vector<Point<ll>> points(n);
    vector<int> who(k);
    vector<bool> vis(n, false);
    for (int i = 0; i < k; i++) {
        cin >> who[i];
        vis[who[i]-1] = true;
    }
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        double MIN = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!vis[j]) continue;
            MIN = min(MIN, (points[i] - points[j]).dist());
        }
        ans = max(ans, MIN);
    }
    cout << fixed << setprecision(16) << ans << endl;
    cout << flush;
    return 0;
}