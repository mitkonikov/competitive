#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x%2].push_back(x);
    }

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    int ans = -1;
    for (int i = 0; i < 2; i++) {
        if (a[i].size() >= 2) {
            ans = max(ans, a[i].rbegin()[0] + a[i].rbegin()[1]);
        }
    }

    cout << ans << endl;
    cout << flush;
    return 0;
}