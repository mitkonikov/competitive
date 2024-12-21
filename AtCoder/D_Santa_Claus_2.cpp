#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const ll dx[4] = { 0, 0, -1, 1 };
const ll dy[4] = { -1, 1, 0, 0 };
const char ch[4] = { 'D', 'U', 'L', 'R' };

int main() {
    ll N, M, SX, SY;
    cin >> N >> M >> SX >> SY;
    vector<pair<ll, ll>> H(N);
    map<ll, vector<ll>> hrow, hcol;
    for (int i = 0; i < N; i++) {
        ll X, Y;
        cin >> X >> Y;
        H[i] = { X, Y };
        hrow[X].push_back(Y);
        hcol[Y].push_back(X);
    }
    ll X = SX, Y = SY;
    map<ll, vector<pair<ll, ll>>> row, col;
    for (int i = 0; i < M; i++) {
        char c;
        ll C;
        cin >> c >> C;
        for (int dir = 0; dir < 4; dir++) {
            if (ch[dir] == c) {
                ll nx = X + dx[dir] * C;
                ll ny = Y + dy[dir] * C;
                if (c == 'L' || c == 'R') {
                    col[Y].push_back({ min(X, nx), max(X, nx) });
                } else {
                    row[X].push_back({ min(Y, ny), max(Y, ny) });
                }
                X = nx;
                Y = ny;
                break;
            }
        }
    }
    set<pair<ll, ll>> visited;
    for (auto& [x, v] : row) {
        if (hrow[x].empty()) continue;
        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        vector<pair<ll, ll>> nv{ v[0] };
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first <= nv.back().second) {
                nv.back().second = max(nv.back().second, v[i].second);
            } else {
                nv.push_back(v[i]);
            }
        }
        for (auto h: hrow[x]) {
            auto it = lower_bound(nv.begin(), nv.end(), pair<ll, ll>{ h, -1e18 });
            if (it != nv.end()) {
                if (h >= it->first && h <= it->second) {
                    visited.insert({ x, h });
                }
            }
            if (it != nv.begin()) {
                it--;
                if (h >= it->first && h <= it->second) {
                    visited.insert({ x, h });
                }
            }
        }
    }
    for (auto& [x, v] : col) {
        if (hcol[x].empty()) continue;
        sort(v.begin(), v.end(), [&](auto& a, auto& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        vector<pair<ll, ll>> nv{ v[0] };
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first <= nv.back().second) {
                nv.back().second = max(nv.back().second, v[i].second);
            } else {
                nv.push_back(v[i]);
            }
        }
        for (auto h: hcol[x]) {
            auto it = lower_bound(nv.begin(), nv.end(), pair<ll, ll>{ h, -1e18 });
            if (it != nv.end()) {
                if (h >= it->first && h <= it->second) {
                    visited.insert({ h, x });
                }
            }
            if (it != nv.begin()) {
                it--;
                if (h >= it->first && h <= it->second) {
                    visited.insert({ h, x });
                }
            }
        }
    }
    cout << X << " " << Y << " " << (int)visited.size() << endl;
    return 0;
}