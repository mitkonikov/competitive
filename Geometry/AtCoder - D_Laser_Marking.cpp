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

struct line {
    vector<Point<double>> p;
    line() { p.resize(2); }
};

int main() {
    int N, S, T;
    cin >> N >> S >> T;
    vector<line> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].p[0].x >> lines[i].p[0].y >> lines[i].p[1].x >> lines[i].p[1].y;
    }
    double ans = LLONG_MAX;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> order(N);
        iota(order.begin(), order.end(), 0);
        do {
            double cur_ans = 0;
            Point<double> prev_point(0, 0);
            for (int j = 0; j < N; j++) {
                int flip = ((i & (1 << j)) > 0);
                auto first_point = lines[order[j]].p[flip];
                auto second_point = lines[order[j]].p[flip ^ 1];
                cur_ans += (first_point - second_point).dist() / T;
                cur_ans += (prev_point - first_point).dist() / S;
                prev_point = second_point;
            }
            ans = min(ans, cur_ans);
        } while (next_permutation(order.begin(), order.end()));
    }
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}