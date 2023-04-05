#include <bits/stdc++.h>
#define ll long long
#define sz(a) (int)(a).size()

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

int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

template<typename T>
int sideOf(Point<T> s, Point<T> e, Point<T> p) { return sgn(s.cross(e, p)); }

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<typename T>
string inHull(const vector<Point<T>>& l, Point<T> p, bool strict = false) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sideOf(l[0], l[a], l[b]) > 0) swap(a, b);
	if (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p) <= -r)
		return "OUT";
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sideOf(l[0], l[c], p) > 0 ? b : a) = c;
	}
    ll c = l[a].cross(l[b], p);
    int N = sz(l);
    for (int i = -3; i <= 3; i++) {
        int na = (a + i + N) % N;
        int nb = (b + i + N) % N;
        if (onSegment(l[na], l[nb], p)) {
            return "ON";
        }
    }
	return (sgn(c) < r ? "IN" : "OUT");
}

int main() {
    int N;
    cin >> N;
    vector<Point<ll>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Point<ll> p;
        cin >> p.x >> p.y;
        cout << inHull(points, p) << endl;
    }
    return 0;
}