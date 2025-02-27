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
    int N, M;
    cin >> N >> M;
    vector<Point<ll>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    struct Triangle {
        string name;
        ll dis;
        ll area;
        bool operator<(const Triangle& other) const {
            // dis/area == other.dist/other.area
            if (dis * other.area == other.dis * area) {
                return name < other.name;
            }
            return dis * other.area > other.dis * area;
        }
    };
    vector<Triangle> tri(M);
    for (int i = 0; i < M; i++) {
        cin >> tri[i].name;
        vector<Point<ll>> t(3);
        for (int i = 0; i < 3; i++) {
            cin >> t[i].x >> t[i].y;
        }
        int dis = 0;
        for (int j = 0; j < N; j++) {
            int pos = 0, neg = 0;
            for (int k = 0; k < 3; k++) {
                ll c = (t[(k+1)%3] - t[k]).cross(points[j] - t[k]);
                if (c >= 0) pos++;
                if (c <= 0) neg++;
            }
            if (pos == 3 || neg == 3) dis++;
        }
        tri[i].dis = dis;
        tri[i].area = abs(t[0].cross(t[1], t[2]));
    }
    sort(tri.begin(), tri.end());
    for (auto el : tri) {
        cout << el.name << endl;
    }
    return 0;
}