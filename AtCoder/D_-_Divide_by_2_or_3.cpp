#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> factors(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        while (a[i] % 2 == 0) {
            a[i] /= 2;
            factors[0][i]++;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
            factors[1][i]++;
        }
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) {
            ok = false;
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    int p[2] = { INT_MAX, INT_MAX };
    for (int rep = 0; rep < 2; rep++) {
        p[rep] = *min_element(factors[rep].begin(), factors[rep].end());
    }

    int ans = 0;
    for (int rep = 0; rep < 2; rep++) {
        for (int i = 0; i < n; i++) {
            ans += (factors[rep][i] - p[rep]);
        }
    }

    cout << ans << endl;
    cout << flush;
    return 0;
}