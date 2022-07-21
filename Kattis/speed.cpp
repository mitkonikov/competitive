#include <bits/stdc++.h>
#define ld long double

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> speeds(n);
    ld left = -1e10, right = 1e10;
    for (int i = 0; i < n; i++) {
        int s, v;
        cin >> s >> v;
        speeds[i] = { s, v };
        left = max(left, (ld)-1.0 * v);
    }

    ld offset = 0;
    for (int it = 0; it < 200; it++) {
        offset = (left + right) / 2;
        ld sum = 0;
        for (int i = 0; i < n; i++) { // v = s/t => t = s/v
            sum += (ld)speeds[i].first / ((ld)speeds[i].second + offset);
        }

        if (sum > m) {
            left = offset;
        } else {
            right = offset;
        }
    }

    cout << setprecision(17) << (left + right) * 0.5 << endl;
    
    return 0;
}