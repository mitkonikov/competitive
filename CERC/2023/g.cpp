#include <bits/stdc++.h>
 
using namespace std;
 
#define double long double
 
typedef complex<double> point;
namespace std {
    bool operator<(point p, point q) {
        if (real(p) != real(q)) return real(p) < real(q);
        return imag(p) < imag(q);
    }
};
 
double dot(point p, point q) { return real(conj(p) * q); }
double cross(point p, point q) { return imag(conj(p) * q); }
double EPS = 1e-8;
 
int sign(double x) {
    if (x < 0) return -1;
    if (x > +EPS) return +1;
    return 0;
}
 
struct circle {
    point p;
    double r;
};
 
struct line {
    point p, q;
    double sq(double x) {
        return x * x;
    }
    double length() {
        return sqrt(sq(real(p) - real(q)) + sq(imag(p) - imag(q)));
    }
    double length2() {
        return sq(real(p) - real(q)) + sq(imag(p) - imag(q));
    }
};
 
vector<point> intersect(line L, circle C) {
    point u = L.p - L.q, v = L.p - C.p;
    double a = norm(u), b = dot(u, v), c = norm(v), det = b * b - a * c, r = b + sqrt(max(det, (double)0.0));
    if (sign(det) < 0) return {};
    return { L.p - (b + sqrt(det)) / a * u, L.p - c / (b + sqrt(det)) * u };
}
 
template<class F>
double ternSearch(double a, double b, F f) {
    assert(a <= b);
    while (b - a >= 1e-14) {
        double mid1 = a + (b - a) / 3;
        double mid2 = a + (b - a) * 2 / 3;
        if (f(mid1) > f(mid2)) a = mid1;
        else b = mid2;
    }
    return f(a);
}
 
double PI = acos(-1.0);
 
double solve(double start, double end, circle C, point A, point B) {
    if (end < start) swap(start, end);
    return ternSearch(start, end, [&](double phi) {
        double X = real(C.p) + C.r * cos(phi);
        double Y = imag(C.p) + C.r * sin(phi);
        line AE = { A, { X, Y } };
        line BE = { B, { X, Y } };
        return AE.length() + BE.length();
    });
}
 
bool inside(point p, line L) {
    double D = dot(p - L.p, L.q - L.p);
    if (D < 0 || norm(p - L.p) > norm(L.q - L.p)) return false;
    return true;
}
 
void testCase() {
    double Ax, Ay, Bx, By, Cx, Cy, R;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> R;
    if (Ax == Bx && Ay == By) Bx += 1e-10;
    point a = { Ax, Ay };
    point b = { Bx, By };
    point c = { Cx, Cy };
    circle C = { c, R };
    line L = { a, b };
    double rA = line{ a, c }.length2();
    double rB = line{ b, c }.length2();
    auto points = intersect(L, C);
    bool are_inside = false;
    for (auto el: points) {
        if (inside(el, L)) are_inside = true;
    }
    if (are_inside || (rA <= R * R && rB <= R * R)) {
        cout << fixed << setprecision(16) << L.length() << endl;
    } else {
        point AB = b - a;
        double phi_start = acos(real(AB) / sqrt(norm(AB)));
        double ans1 = solve(phi_start, phi_start + PI, C, a, b);
        double ans2 = solve(phi_start, phi_start - PI, C, a, b);
        cout << fixed << setprecision(16) << min(ans1, ans2) << endl;
    }
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        testCase();
    }
    return 0;
}
