#include <bits/stdc++.h>
#define endl '\n'

#define ll long long

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1100
#define debug if (0) printf

typedef struct {
    ll x;
    ll y;
    int pr;
} Point;

Point p[MAXN], p0[MAXN];

Point pivot;
inline ll turn(Point a, Point p, Point q) {
    return (p.x - a.x) * (q.y - a.y) - (p.y - a.y) * (q.x - a.x);
}
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool sort_leftof(Point a, Point b) { return turn(p[0], a, b) > 0; }

void testCase() {
	int n;
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p0[i].x >> p0[i].y;
        p0[i].pr = 1;
    }

    double len = 0;
    for (int i = 0; i < n; i++) {
        debug("=== Point %d:  (%f, %f)\n", i, p0[i].x, p0[i].y);
        int ans = n;

        memcpy(p, p0, n * sizeof(Point));
        swap(p[i], p[0]);  // pivot is p0[i];
        for (int j = 1; j < n; j++) {
            if (p[j].x < p[0].x) {
                p[j].x = p[0].x + (p[0].x - p[j].x);
                p[j].y = p[0].y - (p[j].y - p[0].y);
                p[j].pr *= -1;
            }
        }
        sort(p + 1, p + n, sort_leftof);
        debug("Sorted around %f %f:  ", p[0].x, p[0].y);

        int n_left = 0, n_right = 0, f_left = 0,
            f_right = 0;  // n=normal, f=fixed (probability 1) point
        for (int j = 1; j < n; j++) {
            (p[j].pr < 0 ? (p[j].pr == -1 ? f_left : n_left)
                         : (p[j].pr == 1 ? f_right : n_right))++;
        }

        for (int j = 1; j < n; j++) {
            (p[j].pr < 0 ? (p[j].pr == -1 ? f_left : n_left)
                         : (p[j].pr == 1 ? f_right : n_right))--;
            debug("f_left %d, n_left %d, f_right %d, n_right %d\n", f_left,
            n_left, f_right, n_right);
            ans = min({ ans, f_left, f_right });
            (p[j].pr < 0 ? (p[j].pr == -1 ? f_right : n_right)
                         : (p[j].pr == 1 ? f_left : n_left))++;
        }
        
        printf("%d\n", ans);
    }
}

int main() {
    // freopen("bedone.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}