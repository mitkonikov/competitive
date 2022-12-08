// COCI 2022 Round 1

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, r, s;
    cin >> n >> r >> s;

    for (int i = 0; i < n; i++) {
        vector<string> mat(r);
        for (int rr = 0; rr < r; rr++) {
            cin >> mat[rr];
        }

        int mn = r;
        int mx = 0;
        for (int j = 0; j < s; j++) {
            for (int rr = 0; rr < r; rr++) {
                if (mat[rr][j] == '#') {
                    mn = min(mn, r - rr);
                    mx = max(mx, r - rr);
                }
            }
        }

        cout << mx - mn << endl;
    }
    return 0;
}