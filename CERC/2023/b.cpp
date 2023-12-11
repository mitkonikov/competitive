#include <bits/stdc++.h>
 
using namespace std;
 
struct Point {
    int x, y;
    void read() {
        cin >> x >> y;
    }
    double sq(double x) { return x * x; }
    double dist(const Point& a) {
        return sqrt(sq(a.x - x) + sq(a.y - y));
    }
 
    double cross(Point p) const { return x * p.y - y * p.x; };
    double cross(Point a, Point b) const { return (a-*this).cross(b-*this); }
    Point operator-(Point p) const { return Point{ x - p.x, y - p.y }; };
    bool operator==(Point p) const { return (x == p.x && y == p.y); }
    bool operator<(Point p) const { return make_pair(x, y) < make_pair(p.x, p.y); }
};
 
vector<Point> getConvexHull(vector<Point> pts) {
    if (pts.size() <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<Point> h(pts.size() + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
        for (Point p: pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    }
    return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}
 
double solve(vector<Point> points) {
    auto ch = getConvexHull(points);
    double ans = 0;
    for (int i = 0; i < ch.size() / 2; i++) {
        ans += ch[i].dist(ch[(i + ch.size() / 2) % ch.size()]);
    }
    return ans;
}
 
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        points[i].read();
    }
    vector<Point> girls, boys;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'G') girls.push_back(points[i]);
        else boys.push_back(points[i]);
    }
    double ansB = solve(boys);
    double ansG = solve(girls);
    cout << fixed << setprecision(15) << ansB + ansG << endl;
    return 0;
}
