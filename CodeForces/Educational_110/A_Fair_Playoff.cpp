#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a[4];
        vector<pair<int, int>> b;
        cin >> a[0] >> a[1] >> a[2] >> a[3];

        for (int i = 0; i < 4; i++) {
            b.push_back({ a[i], i });
        }

        sort(b.begin(), b.end());

        if ((b[2].second == 1 && b[3].second == 0) || (b[2].second == 0 && b[3].second == 1)) {
            cout << "NO" << endl;
        } else if ((b[2].second == 2 && b[3].second == 3) || (b[2].second == 3 && b[3].second == 2)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}