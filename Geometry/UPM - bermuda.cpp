#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct point {
    ll x, y;

    void read() {
        cin >> x >> y;
    }

    ll cross(point c) {
        return (x * c.y) - (c.x * y);
    }

    ll cross(point a, point b) {
        return (a - *this).cross(b - *this);
    }

    point operator-(const point a) {
        return { x - a.x, y - a.y };
    }
};

struct triangle {
    ll area;
    ll count;
    string name;

    bool operator<(const triangle& t) {
        ll r2 = count * t.area;
        ll r1 = t.count * area;
        if (r2 == r1) return name > t.name;
        return r2 < r1;
    }
};

ll sign(point p1, point p2, point p3) {
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(point pt, point v1, point v2, point v3) {
    ll d1, d2, d3;
    bool has_neg, has_pos;
    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}

int main() {
    int n, t;
    cin >> n >> t;

    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<triangle> triangles(t);
    for (int i = 0; i < t; i++) {
        string name;
        cin >> name;
        vector<point> tpoints(3);
        for (int j = 0; j < 3; j++) {
            tpoints[j].read();
        }

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (PointInTriangle(points[j], tpoints[0], tpoints[1], tpoints[2])) {
                count++;
            }
        }

        ll area = abs(tpoints[0].cross(tpoints[1], tpoints[2]));
        triangles[i] = { area, count, name };
    }

    sort(triangles.rbegin(), triangles.rend());

    for (int i = 0; i < t; i++) {
        cout << triangles[i].name << endl;
    }
    return 0;
}

// Don't have doubles if not needed!
// Read the text for sorting the output!
// Use absolute value of cross product to get area!
// Don't divide the answer if not needed!
// How to find is point in a triangle.