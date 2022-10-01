#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].first >> events[i].second;
    }

    sort(events.begin(), events.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
        return (a.second < b.second);
    });

    int x = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x + d - 1 < events[i].first) {
            ans++;
            x = events[i].second;
        }
    }

    cout << ans << endl;
    return 0;
}