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
    int W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<Point<int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    int A;
    cin >> A;
    vector<int> cA(A);
    for (int i = 0; i < A; i++) cin >> cA[i];
    int B;
    cin >> B;
    vector<int> cB(B);
    for (int i = 0; i < B; i++) cin >> cB[i];
    cA.insert(cA.begin(), 0);
    cA.push_back(W);
    cB.insert(cB.begin(), 0);
    cB.push_back(H);

    sort(points.begin(), points.end());
    vector<Point<int>> container;
    int current_cut_A = 1;
    int mn_ans = INT_MAX, mx_ans = INT_MIN;
    auto process = [&]() {
        // deal with the container
        sort(container.begin(), container.end());

        int last_lb = -1;
        int count = 0;
        for (int j = 0; j < container.size(); j++) {
            auto pj = container[j];
            int lb = lower_bound(cB.begin(), cB.end(), pj.x) - cB.begin();
            if (lb && cB[lb-1] < pj.x) lb--;
            if (lb != last_lb) {
                // update answer
                if (lb != last_lb + 1) mn_ans = 0;
                if (last_lb != -1) {
                    mx_ans = max(mx_ans, count);
                    mn_ans = min(mn_ans, count);
                }
                count = 1;
                last_lb = lb;
            } else {
                count++;
            }
        }
        mx_ans = max(mx_ans, count);
        mn_ans = min(mn_ans, count);
        if (last_lb != cB.size() - 2) mn_ans = 0;
    };
    for (int i = 0; i < N; i++) {
        if (points[i].x < cA[current_cut_A]) {
            container.push_back(Point<int>{ points[i].y, points[i].x });
        } else {
            process();
            container.clear();
            int pc = 0;
            while (points[i].x >= cA[current_cut_A]) {
                current_cut_A++;
                pc++;
            }
            if (pc > 1) mn_ans = 0;
            container.push_back(Point<int>{ points[i].y, points[i].x });
        }
    }
    process();
    if (current_cut_A != cA.size() - 1) mn_ans = 0;
    cout << mn_ans << " " << mx_ans << endl;
    return 0;
}