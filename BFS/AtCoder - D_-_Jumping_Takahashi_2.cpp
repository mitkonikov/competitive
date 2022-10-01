#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct point {
    ll x, y, p;
    
    void read() {
        cin >> x >> y >> p;
    }

    ll man(const point& other) {
        return abs(x - other.x) + abs(y - other.y);
    }
};

int main() {
    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++) {
        v[i].read();
    }

    ll L = 0, R = 4e9 + 1000;
    while (R - L > 1) {
        ll mid = (L + R) / 2;
        
        bool ok = false;
        for (int i = 0; i < n && !ok; i++) {
            queue<int> q;
            q.push(i);
            vector<bool> visited(n, false);
            visited[i] = true;
            while (!q.empty()) {
                int p = q.front();
                q.pop();
                for (int k = 0; k < n; k++) {
                    if (k == p || visited[k]) continue;
                    if (v[p].p * mid >= v[p].man(v[k])) {
                        visited[k] = true;
                        q.push(k);
                    }
                }
            }

            bool ac = true;
            for (int i = 0; i < n; i++) if (!visited[i]) ac = false;
            ok |= ac;
        }
        
        if (ok) R = mid;
        else L = mid+1;
    }

    for (int off = -5; off <= 5; off++) {
        ll mid = L + off;
        if (mid < 0) continue;
        bool ok = false;
        for (int i = 0; i < n && !ok; i++) {
            queue<int> q;
            q.push(i);
            vector<bool> visited(n, false);
            visited[i] = true;
            while (!q.empty()) {
                int p = q.front();
                q.pop();
                for (int k = 0; k < n; k++) {
                    if (k == p || visited[k]) continue;
                    if (v[p].p * mid >= v[p].man(v[k])) {
                        visited[k] = true;
                        q.push(k);
                    }
                }
            }

            bool ac = true;
            for (int i = 0; i < n; i++) if (!visited[i]) ac = false;
            ok |= ac;
        }
        if (ok) {
            cout << mid << endl;
            return 0;
        }
    }
    
    cout << flush;
    return 0;
}