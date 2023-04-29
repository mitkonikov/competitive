#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int max_achievement = 1;
    for (int i = 1; i < n; i++) {
        if (max_achievement < v[i]) {
            max_achievement++;
        } else {
            max_achievement = min(max_achievement, v[i]);
        }
    }

    cout << max_achievement << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt + 1 << ": ";
        testCase();
    }

    return 0;
}