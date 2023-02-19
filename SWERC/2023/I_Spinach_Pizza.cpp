#include <bits/stdc++.h>
#define ll long long

using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
    void read() { cin >> x >> y; }
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
	long double dist() const { return sqrt((long double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	long double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(long double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

int main() {
    int N;
    cin >> N;
    vector<pair<Point<ll>, int>> points(N);
    for (int i = 0; i < N; i++) {
        points[i].first.read();
        points[i].second = i;
    }

    vector<pair<Point<ll>, int>> pts(points);

    auto area = [&](int p) {
        int cN = pts.size();
        return (pts[p].first - pts[(p-1+cN)%cN].first).cross(pts[(p+1)%cN].first - pts[(p-1+cN)%cN].first); 
    };

    long double A = 0, B = 0;
    for (int i = 0; i < N - 2; i++) {
        int mn = 0;
        int cN = pts.size();
        for (int p = 0; p < cN; p++) {
            if (area(p) < area(mn)) {
                mn = p;
            }
        }
        if (i % 2 == 0) A += area(mn);
        else B += area(mn);
        // delete p
        pts.erase(pts.begin() + mn);
    }

    if (A < B) {
        cout << "Alberto" << endl;
    } else {
        cout << "Beatrice" << endl;
    }

    pts.clear();
    pts.resize(N);
    copy(points.begin(), points.end(), pts.begin());
    for (int i = 0; i < N - 2; i++) {
        if ((A < B && i % 2 == 0) || (B <= A && i % 2 == 1)) {
            int mn = 0;
            int cN = pts.size();
            for (int p = 0; p < cN; p++) {
                if (area(p) < area(mn)) {
                    mn = p;
                }
            }
            
            cout << pts[mn].second + 1 << endl;
            pts.erase(pts.begin() + mn);
            continue;
        }
        
        string S;
        cin >> S;
        if (S == "CORRECT" || S == "WRONG-ANSWER") {
            return 0;
        }
        
        int mn = stoi(S) - 1;
        for (int k = 0; k < pts.size(); k++) {
            if (pts[k].second == mn) {
                pts.erase(pts.begin() + k);
                break;
            }
        }
    }

    string S;
    cin >> S;

    return 0;
}