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
    ll dist2() const { return (ll)x*x + (ll)y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2((double)y, (double)x); }
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
    int N;
    cin >> N;
    vector<Point<int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    map<double, map<ll, int>> mp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            auto v = points[j] - points[i];
            mp[v.angle()][v.dist2()]++;
        }
    }
    ll ans = 0;
    ll off = 0;
    for (auto& [angle, dists] : mp) {
        ll sum = 0;
        for (auto& [dist, count] : dists) {
            sum += count;
            off += (ll)(count) * (count - 1) / 2;
        }
        ans += sum * (sum - 1) / 2;
    }
    cout << ans - off / 2 << endl;
    return 0;
}