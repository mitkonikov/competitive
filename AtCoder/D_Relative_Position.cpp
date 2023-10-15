#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct info {
    int pivot, rel, dx, dy;

    void read() {
        cin >> pivot >> rel >> dx >> dy;
        pivot--;
        rel--;
    }
};

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
    vector<info> A(M);
    vector<vector<info>> rel(N), rrel(N);
    for (int i = 0; i < M; i++) {
        A[i].read();
        rel[A[i].pivot].push_back(A[i]);
        rrel[A[i].rel].push_back(A[i]);
    }
    vector<Point<ll>> ans(N, Point<ll>{ 0, 0 });
    vector<bool> visited(N, 0);
    visited[0] = 1;
    queue<int> bfs;
    bfs.push(0);
    while (!bfs.empty()) {
        auto t = bfs.front();
        bfs.pop();
        visited[t] = true;

        for (auto [p, r, dx, dy]: rel[t]) {
            if (visited[r]) {
                continue;
            }

            ans[r] = ans[t] + Point<ll>{ dx, dy };
            bfs.push(r);
        }

        for (auto [p, r, dx, dy]: rrel[t]) {
            if (visited[p]) {
                continue;
            }

            ans[p] = ans[t] - Point<ll>{ dx, dy };
            bfs.push(p);
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "undecidable" << endl;
        } else {
            cout << ans[i].x << " " << ans[i].y << endl;
        }
    }
    return 0;
}