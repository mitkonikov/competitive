#include <bits/stdc++.h>

#include <string>
#include <vector>
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

class UnidirectionalDelivery {
   public:
    #define ll long long
    inline bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
        int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        return (a == 0);
    }

    #define P Point<int>
    inline bool collinear(P a, P b, P c) {
        return collinear(a.x, a.y, b.x, b.y, c.x, c.y);
    }

    inline bool col_vec(vector<Point<int>> points) {
        if (points.size() < 2) return true;
        bool ok = 1;
        for (int i = 2; i < points.size(); i++) {
            ok &= collinear(points[i], points[i-1], points[i-2]);
        }
        return ok;
    }

    int calculateBestDeliveryPlan(int numFans, vector<int> fanX,
                                  vector<int> fanY) {
        vector<Point<int>> points(numFans);
        for (int i = 0; i < numFans; i++) {
            points[i] = Point<int>{ fanX[i], fanY[i] };
        }
        vector<int> dp((1 << numFans));
        for (int i = 0; i < (1 << numFans); i++) {
            vector<Point<int>> current;
            for (int j = 0; j < numFans; j++) {
                if (i & (1 << j)) current.push_back(points[j]);
            }
            dp[i] = col_vec(current) ? 1 : 1e9;
        }
        for (int mask = 0; mask < (1 << numFans); mask++) {
            for(int i = mask; i > 0; i = (i-1) & mask){
                dp[mask] = min(dp[mask], dp[mask^i] + dp[i]);
            }
        }
        return dp[(1 << numFans) - 1];
    }
};

int main() {
    UnidirectionalDelivery d;
    cout << d.calculateBestDeliveryPlan(11, {0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 4}, {0, 2, 3, 0, 4, 1, 2, 0, 0, 3, 4}) << endl;
    cout << d.calculateBestDeliveryPlan(16, {0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 4, 10, 20, 30, 50, 20, 301, 30}, {0, 2, 3, 0, 4, 1, 2, 0, 0, 3, 4, 31, 41, 23, 241, 23, 24, 123, 13, 123}) << endl;
    return 0;
}