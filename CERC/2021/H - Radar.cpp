#include <bits/stdc++.h>
#include <cmath>
#define endl '\n'
#define ll long long
#define ld long double
 
using namespace std;
 
struct point {
    ld x, y;
    ld angle = 0;
    
    ld dist() {
        return sqrt(x * x + y * y);
    }
 
    void read(bool norm=true) {
        cin >> x >> y;
        angle = atan2(y, x);
        if (angle < 0) {
            angle += (ld)2 * M_PI;
        }
        if(norm) {
            ld nx = x / dist();
            ld ny = y / dist();
            x = nx;
            y = ny;   
        } 
    }
 
    ld dot(const point &o) {
        return x * o.x + y * o.y;
    }
 
    ld dist(const point &p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
 
    point times(ld scalar) {
        return { x * scalar, y * scalar };
    }
};
 
template<typename T> 
T bin(function<bool(T)> f, T start, T end) {
    // [start, end)
    if (end <= start) return end;
    if (!f(end - 1)) return end;
    while (end - start > 1) {
        T mid = (start + end) / 2;
        if (f(mid)) end = mid; else start = mid;
    }
 
    return (f(start) ? start : end);
}
 
int main(){
    int r, a, q;
    cin >> r >> a >> q;
 
    vector<int> dists(r);
    for (int i = 0; i < r; i++) {
        cin >> dists[i];
    }
 
    sort(dists.begin(), dists.end());
 
    vector<point> angles(a);
    for (int i = 0; i < a; i++) {
        point p;
        p.read();
        angles[i] = p;
    }
 
    sort(angles.begin(), angles.end(), [&](const point &a, const point &b) {
        return (a.angle < b.angle);
    });
 
    angles.insert(angles.begin(), angles[a - 1]);
    angles[0].angle -= (ld)2 * M_PI;
    angles.push_back(angles[1]);
    angles.back().angle += (ld)2 * M_PI;
 
    auto closest = [&](point p, point v) {
        ld target = p.dot(v);
        int idx = bin<int>([&](int id) {
            return dists[id] > target;
        }, 0, r);
 
        ld ans = p.dist(v.times(dists[idx]));
        if (idx > 0) {
            ans = min(ans, p.dist(v.times(dists[idx - 1])));
        }
 
        return ans;
    };
 
    for (int i = 0; i < q; i++) {
        point p;
        p.read(false);
        ld p_angle = p.angle;
        int angleR =  bin<int>([&](int i) {
            return (p_angle <= angles[i].angle);
        },  0, a + 2);
 
        ld ansR = closest(p, angles[angleR]);
        ld ansL = closest(p, angles[angleR - 1]);
        cout << fixed << setprecision(10) << min(ansL, ansR) << endl;
    }
 
    cout << flush;
    return 0;
}