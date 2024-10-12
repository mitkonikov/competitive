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

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int main() {
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    auto points = [N](int i) {
        vector<Point<int>> p;
        p.emplace_back(i, i);
        p.emplace_back(i, N-i-1);
        p.emplace_back(N-i-1, N-i-1);
        p.emplace_back(N-i-1, i);
        return p;
    };
    auto create_string = [&](int i) {
        string S = "";
        auto ps = points(i);
        auto current = ps[0];
        for (int dir = 0; dir < 4; dir++) {
            while (!(current == ps[(dir + 1) % 4])) {
                S += A[current.x][current.y];
                current.x += dx[dir];
                current.y += dy[dir];
            }
        }
        return S;
    };
    vector<string> strs;
    for (int i = 0; i < N / 2; i++) {
        string S1 = create_string(i);
        int one_rotation = N - (i * 2) - 1;
        int by = ((4 - ((i + 1) % 4)) % 4) * one_rotation;
        rotate(S1.begin(), S1.begin() + by, S1.end());
        strs.push_back(S1);
    }
    vector<string> ans(A);
    auto write_string = [&](int i, string S) {
        int pointer = 0;
        auto ps = points(i);
        auto current = ps[0];
        for (int dir = 0; dir < 4; dir++) {
            while (!(current == ps[(dir + 1) % 4])) {
                ans[current.x][current.y] = S[pointer++];
                current.x += dx[dir];
                current.y += dy[dir];
            }
        }
        return S;
    };
    for (int i = 0; i < N / 2; i++) {
        write_string(i, strs[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}