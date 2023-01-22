#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
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
};

#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P> int extrVertex(vector<P>& poly, P dir) {
	int n = sz(poly), lo = 0, hi = n;
	if (extr(0)) return 0;
	while (lo + 1 < hi) {
		int m = (lo + hi) / 2;
		if (extr(m)) return m;
		int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
		(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
	}
	return lo;
}

#define cmpL(i) sgn(a.cross(poly[i], b))
template <class P>
vector<int> lineHull(P a, P b, vector<P>& poly) {
	int endA = extrVertex(poly, (a - b).perp());
	int endB = extrVertex(poly, (b - a).perp());
    if (cmpL(endA) < 0 || cmpL(endB) > 0)
		return {-1, -1};
	vector<int> res(2);
	rep(i,0,2) {
		int lo = endB, hi = endA, n = sz(poly);
		while ((lo + 1) % n != hi) {
			int m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;
			(cmpL(m) == cmpL(endB) ? lo : hi) = m;
		}
		res[i] = (lo + !cmpL(hi)) % n;
		swap(endA, endB);
	}
	if (res[0] == res[1]) return {res[0], -1};
	if (!cmpL(res[0]) && !cmpL(res[1]))
		switch ((res[0] - res[1] + sz(poly) + 1) % sz(poly)) {
			case 0: return {res[0], res[0]};
			case 2: return {res[1], res[1]};
		}
	return res;
}

const double EPS = 1E-9;

struct seg {
  Point<ll> p, q;
  int id;

  double get_y(double x) const {
    if (abs(p.x - q.x) < EPS) return p.y;
    return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
  }
};

bool intersect1d(double l1, double r1, double l2, double r2) {
  if (l1 > r1) swap(l1, r1);
  if (l2 > r2) swap(l2, r2);
  return max(l1, l2) <= min(r1, r2) + EPS;
}

#define pt Point<ll>
int vec(const pt& a, const pt& b, const pt& c) {
  double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b) {
  return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
         intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
         vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
         vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

const ll INF = 6e9;

vector<double> tangents(Point<ll> S, vector<Point<ll>>& poly) {
    int N = poly.size();
    vector<double> dp(N, INF);
    for (int i = 0; i < N; i++) {
        auto v = lineHull(S, poly[i], poly);
        if (v[1] == -1) {
            dp[i] = (S-poly[i]).dist();
        }
    }
    for (int i = 0; i < 2 * N; i++) {
        if (dp[i%N] + (poly[i%N]-poly[(i+1)%N]).dist() < dp[(i+1)%N]) {
            dp[(i+1)%N] = dp[i%N] + (poly[i%N]-poly[(i+1)%N]).dist();
        }
    }
    for (int i = 2 * N; i >= 0; i--) {
        if (dp[i%N] + (poly[i%N]-poly[(i-1+N)%N]).dist() < dp[(i-1+N)%N]) {
            dp[(i-1+N)%N] = dp[i%N] + (poly[i%N]-poly[(i-1+N)%N]).dist();
        }
    }
    return dp;
}

int main() {
    int N;
    cin >> N;
    vector<Point<ll>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    Point<ll> S, T;
    cin >> S.x >> S.y >> T.x >> T.y;
    auto res = lineHull(S, T, points);
	bool dont_swim = false;
	auto seg_int = intersect({ S, T }, { points[res[0]], points[(res[0]+1)%N] });
    if (!seg_int) {
        cout << fixed << setprecision(15) << (S-T).dist() << endl;
        return 0;
    }
    auto dp1 = tangents(S, points);
    auto dp2 = tangents(T, points);
    double ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp1[i] + dp2[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}