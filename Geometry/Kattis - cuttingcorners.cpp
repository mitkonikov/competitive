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
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<Point<ll>> points(n);
        for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

        auto getSmallest = [](vector<Point<ll>> points) {
            int n = points.size();
            auto angleAt = [points, n](int i) {
                auto p1 = points[i%n];
                auto p2 = points[(i+1)%n];
                auto p3 = points[(i+2)%n];
                auto v = p1 - p2;
                auto u = p3 - p2;
                // cos theta = (v dot u) / (len(v) * len(u))
                auto cosTheta = v.dot(u) / (v.dist() * u.dist());
                return acos(cosTheta);
            };
            double smallest = 100000;
            int id = -1;
            for (int i = 0; i < n; i++) {
                auto a = angleAt(i);
                if (a < smallest) {
                    smallest = a;
                    id = (i+1)%n;
                }
            }
            return make_pair(smallest, id);
        };

        while (true) {
            if (points.size() == 3) break;
            auto small = getSmallest(points);
            auto rem = points[small.second];
            points.erase(points.begin() + small.second);
            auto small2 = getSmallest(points);
            if (small2.first < small.first) {
                points.insert(points.begin() + small.second, rem);
                break;
            }
            if (points.size() == 3) break;
        }

        cout << points.size() << " ";
        for (auto p: points) cout << p.x << " " << p.y << " ";

        cout << endl;
    }
    cout << flush;
    return 0;
}