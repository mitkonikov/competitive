#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ll cx, cy, r, d;
    char ch_rob, ch_inside, ch_all;
    ll w, h;
    ll p, q;
    cin >> cx >> cy >> r >> d >> ch_rob >> ch_inside >> w >> h >> p >> q >> ch_all;
 
    cx = (cx - p);
    cy = h - (cy - q);
    
    vector<vector<char>> mat(h + 2, vector<char>(w + 2, ch_all));
    const ll dx[4] = { 0, 1, 0, 1 };
    const ll dy[4] = { 0 , 0, 1, 1 };
    auto dist = [&](ll x1, ll y1, ll x2, ll y2) {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool rob = 0;
            bool inside = 0;
            bool outside = 0;
            for (int dir = 0; dir < 4; dir++) {
                ll nx = i + dx[dir];
                ll ny = j + dy[dir];
                ll D = dist(ny, nx, cx, cy);
                if (D >= r * r && D <= (r + d) * (r + d)) {
                    rob = 1;
                } else if (D <= r * r) {
                    inside = 1;
                } else if (D > (r + d) * (r + d)) {
                    outside = 1;
                }
            }
 
            if (rob || (inside && outside)) {
                mat[i][j] = ch_rob;
            } else if (inside) {
                mat[i][j] = ch_inside;
            }
        }
    }
 
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << mat[i][j];
        } cout << endl;
    }
    return 0;
}