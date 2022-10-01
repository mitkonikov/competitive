#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'

using namespace std;

template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return abs(x - p.y) <= 1e-9 && abs(y - p.y) <= 1e-9; }
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
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<Point<ll>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    vector<pair<Point<ll>, Point<ll>>> lines;
    lines.reserve(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto dir = points[j] - points[i];
            bool ok = true;
            for (int l = 0; l < lines.size(); l++) {
                auto one = lines[l].first;
                auto two = lines[l].second;
                if (points[i].cross(one, points[j]) == 0
                    && points[i].cross(two, points[j]) == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) lines.push_back({ points[i], points[j] });
        }
    }

    int ans = 0;
    for (int l = 0; l < lines.size(); l++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            auto one = lines[l].first;
            auto two = lines[l].second;
            if (points[j].cross(one, two) == 0) {
                count++;
            }
        }

        if (count >= k) ans++;
    }

    cout << ans << endl;
    
    return 0;
}