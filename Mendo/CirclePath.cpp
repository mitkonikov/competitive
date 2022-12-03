#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> r(n);
    int p1, p2, m;
    cin >> r[0] >> p1 >> p2 >> m;
    for (int i = 1; i < n; i++) {
        r[i] = ((ll)r[i-1] * p1 + p2) % m;
    }
    auto solve = [&]() {
        vector<int> steps(n, INT_MAX);
        queue<int> q;
        q.push(s);
        steps[s] = 0;
        int L = s, R = s;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top == t) {
                return steps[t];
            }

            int newL = (top - r[top] + n) % n;
            int newR = (top + r[top]) % n;
            
            bool okL = false;
            if (L <= R && top - r[top] < L) {
                okL = true;
            } 
            if (L >= R && newL < L && newL > R) {
                okL = true;
            }

            if (okL) {
                for (int i = (L-1+n)%n;; i = (i-1+n)%n) {
                    if (steps[i] != INT_MAX) break;
                    steps[i] = steps[top] + 1;
                    q.push(i);
                    L = i;
                    if (i == newL) break;
                }
            }
            
            bool ok = false;
            if (R <= L && newR > R && newR < L) {
                ok = true;
            } 
            if (R >= L && top + r[top] > R) {
                ok = true;
            }
            if (ok) {
                int iter = 0;
                for (int i = (R+1)%n;; i = (i+1+n)%n) {
                    if (steps[i] != INT_MAX) break;
                    steps[i] = steps[top] + 1;
                    q.push(i);
                    R = i;
                    iter++;
                    if (i == newR) break;
                }
            }
        }
        return -1;
    };
    int e = solve();
    cout << e << endl;
    return 0;
}